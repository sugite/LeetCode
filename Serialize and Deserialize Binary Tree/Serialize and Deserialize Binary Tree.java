/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return null;
        StringBuffer sb = new StringBuffer();
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);
        int count = 0;
        while (queue.size() > 0) {
            TreeNode cur = queue.removeFirst();
            if (cur == null) {
                count += 1;
            } else {
                while (count > 0) {
                    sb.append("#,");
                    count -= 1;
                }
                sb.append(String.valueOf(cur.val)).append(",");
                queue.addLast(cur.left);
                queue.addLast(cur.right);
            }
        }
        return sb.deleteCharAt(sb.length()-1).toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) return null;
        String[] list = data.split(",");
        LinkedList<TreeNode> backup = new LinkedList<>();
        int index = 1;
        TreeNode root = new TreeNode(Integer.valueOf(list[0]));
        TreeNode cur = root;
        while (index < list.length) {
            TreeNode left = null;
            if (!list[index].equals("#")){
                left = new TreeNode(Integer.valueOf(list[index]));
            }
            cur.left = left;
            index += 1;
            TreeNode right = null;
            if (index < list.length && !list[index].equals("#")){
                right = new TreeNode(Integer.valueOf(list[index]));
            }
            cur.right = right;
            backup.addLast(cur.left);
            backup.addLast(cur.right);
            while (backup.getFirst() == null) {
                backup.removeFirst();
            }
            cur = backup.removeFirst();
            index += 1;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));