/**
 * @param {number[]} nums
 * @return {number}
 */

function helper(nums, i, dp){
    if(i>=nums.length){
        return 0;
    }
    if(dp[i] !== -1){
        return dp[i];
    }
    return dp[i] = Math.max(helper(nums, i+2, dp)+nums[i], helper(nums, i+1, dp));
}
var rob = function(nums) {
    if( nums.length === 1){
        return nums[0]
    }
    const dp = new Array(n+1).fill(-1);
    return Math.max(helper(nums.slice(0, nums.length-1), 0, dp), helper(nums.slice(1, nums.length), 0, dp));
};