/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    private var first: TreeNode?
    private var second: TreeNode?
    private var prev = TreeNode(Int.min)
    func recoverTree(_ root: TreeNode?) {
        inOrder(root)
        guard let first = first, let second = second else {
            return
        }
        var tmp = first.val
        first.val = second.val
        second.val = tmp
    }
    
    func inOrder(_ root: TreeNode?) {
        guard let root = root else {
            return
        }
        inOrder(root.left)
        if root.val < prev.val {
            if first == nil {
                first = prev
            }
            second = root
        }
        prev = root
        inOrder(root.right)
    }
}