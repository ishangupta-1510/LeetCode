class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        int res = 0;
        int l = 0;
        int t = 0;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            t = max(m[s[i]],t);
            if(i-l+1-t>k){
                m[s[l]]--;
                l++;
            }
            else{
                res = i-l+1;
            }
        }
        return res;
    }
};