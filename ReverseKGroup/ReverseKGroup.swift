class Solution {
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard k > 1 else { return head }
        
        var (cur, subHead) = (head, head)
        var ret: ListNode? = nil
        var prev: ListNode? = nil
        var count = 1
        while cur != nil {
            if count == k {
                ret = ret ?? cur
                reverseList(subHead, cur)
                prev?.next = cur
                (prev, cur) = (subHead, subHead)
                subHead = subHead?.next
                count = 0
            }
            cur = cur!.next
            count += 1
        }
        
        return ret ?? head
    }
    
    func reverseList(_ head: ListNode?, _ last: ListNode?) {
        var (lastNext, cur) = (last?.next, head)
        while cur !== last {
            var next = cur?.next
            last?.next = cur
            cur?.next = lastNext
            lastNext = cur
            cur = next
        }
    }
}