class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        vector<int> freq(128,0);
        for(int i=0;i<m;i++){
            freq[t[i]]++;
        }
        int start = 0,len = INT_MAX,required=m,minstart=0;
        for(int end=0;end<n;end++){
            if(freq[s[end]] > 0){
                required--;
            }
            freq[s[end]]--;
            while(required == 0){
                if (end - start + 1 < len) {
                    len = end - start + 1;
                    minstart = start;
                }
                freq[s[start]]++;
                if(freq[s[start]]>0){
                    required++;
                }
                start++;
            }
        }
        if(len == INT_MAX){
            return "";
        }
        return s.substr(minstart,len);
    }
};