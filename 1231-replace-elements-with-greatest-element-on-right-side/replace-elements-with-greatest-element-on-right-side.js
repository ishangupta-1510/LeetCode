/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    let n = arr.length;
    let mx = arr[n-1];
    arr[n-1] = -1
    if(n===1){
        return arr;
    }
    for(let i=n-2;i>=0;i--){
        let temp = arr[i];
        arr[i] = mx;
        if(temp > mx){
            mx = temp;
        }
    }
    return arr;
};