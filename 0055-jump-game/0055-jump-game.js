/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let maxJump = nums[0];
    for(let i=0;i<nums.length;i++){
        maxJump = Math.max(maxJump-1,nums[i]);
        if(maxJump <= 0 && i!== nums.length){
            return false;
        }
    }
    return true;
};