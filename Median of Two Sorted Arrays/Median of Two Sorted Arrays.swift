class Solution {
    func findKth(_ nums1: [Int], _ begin1: Int, _ len1: Int, _ nums2: [Int], _ begin2: Int, _ len2: Int, _ k: Int) -> Int {
        if len1 < len2 {
            return findKth(nums2, begin2, len2, nums1, begin1, len1, k)
        }
        if len2 == 0 {
            return nums1[k - 1 + begin1]
        }
        if k == 1 {
            return min(nums1[begin1], nums2[begin2])
        }
        let index = min(len2, k / 2)
        if nums1[index - 1 + begin1] > nums2[index - 1 + begin2] {
            return findKth(nums1, begin1, len1, nums2, index + begin2, len2 - index, k - index)
        } else {
            return findKth(nums1, index + begin1, len1 - index, nums2, begin2, len2, k - index)
        }
    }

    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        let left = (nums1.count + nums2.count + 1) / 2
        let right = (nums1.count + nums2.count + 2) / 2
        return Double(findKth(nums1, 0, nums1.count, nums2, 0, nums2.count, left) + findKth(nums1, 0, nums1.count, nums2, 0, nums2.count, right)) / 2.0
    }
}