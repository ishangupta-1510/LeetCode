/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArr = [];
    let k = 0;
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            filteredArr[k] = arr[i];
            k++;
        }
    }
    return filteredArr;
};