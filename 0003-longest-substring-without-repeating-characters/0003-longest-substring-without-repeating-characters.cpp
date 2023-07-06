class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count = 0;
        int mcount = 0;
        for(int i=0;i<n;i++){
            map<char,int> m;
            int j=i;
            while(!m[s[j]] and j<n){
                
                m[s[j]]++;
                j++;
                count++;
            }
            mcount = max(mcount,count);
            count = 0;
        }
        return mcount;
    }
};