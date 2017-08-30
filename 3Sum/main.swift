class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        var res = [[Int]]()
        guard nums.count >= 3 else {
            return res
        }
        var _nums = nums
        _nums.sort()
        for i in 0 ..< _nums.count - 2 {
            if i == 0 || _nums[i] != _nums[i - 1] {
                twoSum(_nums, i + 1, -_nums[i], &res)
            }
        }
        return res
    }
    
    func twoSum(_ nums: [Int], _ start: Int, _ target: Int, _ res: inout [[Int]]) {
        var left = start
        var right = nums.count - 1
        while left < right {
            let sum = nums[left] + nums[right]
            if sum == target {
                res.append([-target, nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right && nums[left] == nums[left - 1] {
                    left += 1
                }
                while left < right && nums[right] == nums[right + 1] {
                    right -= 1
                }
            } else if sum < target {
                left += 1
            } else {
                right -= 1
            }
        }
    }
}