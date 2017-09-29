/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[]}
 */
let maxNumber = function(nums1, nums2, k) {
    if (k === 0) { return []; }

    let ret = new Array(k);
    ret.fill(0);
    for (let i = 0; i <= k; i++) {
        if (i <= nums1.length && k - i <= nums2.length) {
            let arr1 = extract(nums1, i);
            let arr2 = extract(nums2, k - i);
            let max_candidate = mergeArr(arr1, arr2);
            if (compareArr(max_candidate, ret)) {
                ret = max_candidate;
            }
        }
    }
    return ret;
};

let compareArr = function (a, b) {
    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) { return a[i] > b[i]; }
    }
    return false;
};

let extract = function (nums, k) {
    let ret = [], last = nums.length - k;
    for (let i = 0; i < nums.length; i++) {
        while (last > 0 && ret.length > 0 && nums[i] > ret[ret.length - 1]) { ret.pop(); last--; }
        ret.push(nums[i]);
    }
    return ret.slice(0, k);
};

let mergeArr = function (nums1, nums2) {
    let ret = [], i = 0, j = 0;
    while(i < nums1.length && j < nums2.length) {
        if (nums1[i] > nums2[j]) {
            ret.push(nums1[i++]);
        } else if (nums1[i] < nums2[j]) {
            ret.push(nums2[j++]);
        } else {
            let ii = i, jj = j;
            while (ii < nums1.length && jj < nums2.length && nums1[ii] === nums2[jj]) { ii++; jj++; }
            if (ii !== nums1.length && (jj === nums2.length || nums1[ii] > nums2[jj])) {
                ret.push(nums1[i++]);
            } else {
                ret.push(nums2[j++]);
            }
        }
    }
    return ret.concat(nums1.slice(i, nums1.length)).concat(nums2.slice(j, nums2.length));
};