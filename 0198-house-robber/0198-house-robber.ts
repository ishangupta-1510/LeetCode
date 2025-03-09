function rob(nums: number[]): number {
    if (nums.length === 0) return 0; // Handle empty array case
    const dp: number[] = new Array(nums.length).fill(-1);
    return rec(nums.length - 1, nums, dp);
}

function rec(i: number, nums: number[], dp: number[]): number {
    if (i < 0) return 0; // Base case: No house to rob
    if (dp[i] !== -1) return dp[i]; // Return cached value

    dp[i] = Math.max(rec(i - 1, nums, dp), nums[i] + rec(i - 2, nums, dp));
    return dp[i];
}
