/**
 * @param {number[]} nums
 * @return {number}
 */
function merge(items, start, mid, end){
    var left = items.slice(start, mid + 1),
        right = items.slice(mid + 1, end + 1),
        result  = [],
        il      = 0,
        ir      = 0;

    while (il < left.length && ir < right.length){
        if (left[il] < right[ir]){
            result.push(left[il++]);
        } else {
            result.push(right[ir++]);
        }
    }

    result = result.concat(left.slice(il)).concat(right.slice(ir));
    for (var i = 0; i < result.length; i++) {
        items[start + i] = result[i];
    }
}

function mergeSort(items, start, end){
    if (start >= end) {
        return 0;
    }
    var mid = Math.floor((start + end) / 2);
    var count = mergeSort(items, start, mid) + mergeSort(items, mid + 1, end);
    var j = mid + 1;
    for (var i = start; i <= mid; i++) {
        while (j <= end && items[i] > items[j] * 2) {
            j++;
        }
        count += j - (mid + 1);
    }
    merge(items, start, mid, end);
    return count;
}

var reversePairs = function(nums) {
    return mergeSort(nums, 0, nums.length - 1)
};