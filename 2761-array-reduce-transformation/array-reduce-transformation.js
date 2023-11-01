/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let n = nums.length;
    if(n==0){
        return init;
    }
    let val = fn(init,nums[0]);
    for(let i=1;i<n;i++){
        val = fn(val,nums[i]);
    }
    return val;
};