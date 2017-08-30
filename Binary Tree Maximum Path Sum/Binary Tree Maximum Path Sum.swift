class Solution {
    func maxPathSum(_ root: TreeNode?) -> Int {
        let (ret, _) = helper(root)
        return ret
    }
    
    // 第一个返回全局最大，第二个返回单路径最大
    func helper(_ root: TreeNode?) -> (Int, Int){
        guard let root = root else {
            return (Int.min, Int.min)
        }
        
        let (l1, l2) = helper(root.left)
        let (r1, r2) = helper(root.right)
        
        let single_max = max(root.val, root.val + max(l2, r2, 0))
        let global_max = max(single_max, root.val + max(l2, 0) + max(r2, 0), l1, r1)
        
        return (global_max, single_max)
    }
}