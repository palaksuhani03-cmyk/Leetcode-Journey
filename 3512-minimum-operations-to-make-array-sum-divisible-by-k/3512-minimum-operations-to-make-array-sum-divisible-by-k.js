/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k) {
    let sum = 0;

    // Calculate sum of array
    for (let num of nums) {
        sum += num;
    }

    // If already divisible by k → 0 operations
    let rem = sum % k;
    if (rem === 0) return 0;

    // Otherwise we need to remove exactly `rem` from the sum
    // We can only do it by decreasing any element one step at a time.
    return rem;
};