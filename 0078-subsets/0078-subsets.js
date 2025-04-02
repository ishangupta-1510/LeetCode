/**
 * @param {number[]} nums
 * @return {number[][]}
 */

function gsubsets(nums, i, res, temp){
    if(i>=nums.length){
        res.push([...temp]);
        return;
    }
    gsubsets(nums,i+1,res,temp);
    temp.push(nums[i]);
    gsubsets(nums,i+1,res,temp);
    temp.pop(); 
}
var subsets = function(nums) {
    let res = [];
    let temp = [];
    gsubsets(nums,0,res,temp);
    return res;
};