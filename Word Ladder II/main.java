class Node {
    public String word;
    public int level;
    public Node parent;

    public Node(String word, int level, Node parent) {
        this.word = word;
        this.level = level;
        this.parent = parent;
    }
}

public class Solution {
    public int minlevel = Integer.MAX_VALUE;

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> result = new ArrayList<>();
        Map<String, List<String>> nexts = new HashMap<>();
        for (String word : wordList)
            nexts.put(word, new ArrayList<>());
        nexts.put(beginWord,new ArrayList<>());
        List<Node> q = new LinkedList<>();
        Node begin = new Node(beginWord, 0, null);
        q.add(begin);
        Set<String> words = new HashSet<>(wordList);
        while(!q.isEmpty()) {
            Node tmp = q.remove(0);
            words.remove(tmp.word);
            if (tmp.word.equals(endWord) && tmp.level <= minlevel) {
                minlevel = tmp.level;
                Node tail = tmp;
                List<String> res = new ArrayList<>();
                while(tail != null) {
                    res.add(tail.word);
                    tail = tail.parent;
                }
                Collections.reverse(res);
                result.add(res);
            }
            if (tmp.level > minlevel) continue;
            if (nexts.get(tmp.word).isEmpty()) {
                char[] tmpWord = tmp.word.toCharArray();
                for (int i = 0; i < tmpWord.length; i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        tmpWord[i] = ch;
                        String newWord = String.copyValueOf(tmpWord);
                        if (words.contains(newWord)) {
                            nexts.get(tmp.word).add(newWord);
                            q.add(new Node(newWord, tmp.level + 1, tmp));
                        }
                    }
                    tmpWord = tmp.word.toCharArray();
                }
            } else {
                for (String word : nexts.get(tmp.word)) {
                    if (words.contains(word)) {
                        q.add(new Node(word, tmp.level + 1, tmp));
                    }
                }
            }
        }

        return result;
    }
}