/**
 * @param {string} s
 * @return {number}
 */

function decoding(s,i){
    if(s[i] === '0'){
        return 0;
    }
    if(i >= s.length - 1){
        return 1;
    }
    let res = decoding(s,i+1);
    if((s[i] === '1' && i<s.length -1) || (s[i] === '2' && i<s.length-1 && s[i+1] <'7'))
        res += decoding(s,i+2);
    
    return res;
}
var numDecodings = function(s) {
    return decoding(s,0);
};