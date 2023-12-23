/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let m = new Map();
    let n = nums.length;
    for(let i=0;i<n;i++){
        if(m.has(target-nums[i])){
            return [i,m.get(target-nums[i])];
        }
        m.set(nums[i],i);
    }
    return -1;
};