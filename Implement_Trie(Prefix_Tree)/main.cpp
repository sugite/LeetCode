class TrieNode {
public:
    // Initialize your data structure here.
    bool leaf ;
    TrieNode* children[26];
    TrieNode() {
        leaf = false;
        fill_n(children, 26, nullptr);
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        root->leaf = true;
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if(s.size()==0) return ;
        int i = 0 ;
        TrieNode *cur = root;
        while(i < s.size() && cur->children[s[i]-'a']){
            cur = cur->children[s[i++]-'a'];
        }
        while(i < s.size()){
                cur = cur->children[s[i]-'a'] = new TrieNode();
                ++i;
        }
        cur->leaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if(key.size()==0) return false;
        TrieNode *cur = root;
        int i = 0 ;
        while(i < key.size() && cur->children[key[i]-'a']){
            cur = cur->children[key[i++]-'a'] ;
        }
        return i==key.size() && cur->leaf ;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.size() == 0) return false;
        TrieNode *cur = root;
        int i = 0 ;
        while(i < prefix.size() && cur->children[prefix[i]-'a']){
            cur = cur->children[prefix[i++]-'a'] ;
        }
        return i==prefix.size();
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");