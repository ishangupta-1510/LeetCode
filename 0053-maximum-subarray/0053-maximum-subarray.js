/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let hasPositive = false, currMax = 0, max = 0, maxNeg = nums[0];
    for(let i=0;i< nums.length;i++){
        if(nums[i] > 0){
            hasPositive = true;
        }
        else{
            maxNeg = Math.max(maxNeg, nums[i]);
        }
        currMax += nums[i];
        max = Math.max(currMax, max);
        if(currMax < 0){
            currMax = 0;
        }
    }
    if(hasPositive !== true){
        return maxNeg;
    }
    return max;
};