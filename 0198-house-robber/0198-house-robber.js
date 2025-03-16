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
    if (nums.length === 0) return 0;
    const dp = new Array(nums.length+1).fill(-1);
    return helper(nums, 0, dp);
};