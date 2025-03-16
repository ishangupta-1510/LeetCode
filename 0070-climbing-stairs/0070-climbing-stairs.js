/**
 * @param {number} n
 * @return {number}
 */

function helper(n, dp){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(dp[n] !== -1){
        return dp[n];
    }
    dp[n] = helper(n-1, dp)+helper(n-2, dp);
    return dp[n];
}
var climbStairs = function(n) {
    const dp = new Array(n+1).fill(-1);
    return helper(n, dp);
};