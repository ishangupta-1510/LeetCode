class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[30] = {0};
        int freq2[30] = {0};
        int n = s.size(),m=t.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            freq1[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            freq2[t[i]-'a']++;
        }
        for(int i=0;i<27;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};