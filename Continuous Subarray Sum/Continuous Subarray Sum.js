/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
    var map = {},
        sum = 0;
    for (var i = 0; i < nums.length; i++) {
        sum += nums[i];
        if (k === 0 && sum === 0 && i > 0) {
            return true;
        }
        if (k !== 0) {
            var mod = sum % k;
            if (mod === 0 && i > 0) {
                return true;
            }
            if (map.hasOwnProperty(mod)) {
                return true;
            } else {
                map[mod] = i;
            }
        }
    }
    return false;
};