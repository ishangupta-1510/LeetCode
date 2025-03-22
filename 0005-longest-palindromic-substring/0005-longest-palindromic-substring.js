/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let dp = [];
    let start = 0, end = 0, max = 0;;
    for(let i=0;i<s.length;i++){
        const tempArr = [];
        for(let j=0;j<s.length;j++){
            if(i === j || i === j+1){
                tempArr.push(1)
            }
            else {
                tempArr.push(0);
            }
        }
        dp.push(tempArr);
    }
    let k = 0;
    while(k < s.length - 1){
        let i = 0, j = k+1;
        while(j < s.length){
            if(s[i] === s[j]){
                if(j-i === 1){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = dp[i+1][j-1] ? dp[i+1][j-1] + 2 : 0;
                }
                if(max < dp[i][j]){
                    max = dp[i][j];
                    start = i;
                    end = j;
                }
            }
            j++;
            i++;
        }
        k++;
    }
    console.log(dp);
    return s.slice(start, end+1);
};