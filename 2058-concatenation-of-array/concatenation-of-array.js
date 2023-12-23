/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function(nums) {
    let n = nums.length;
    let arr = new Array(2*n);
    for(let i=0;i<2*n;i++){
        arr[i] = nums[i%n];
    }
    return arr;
};