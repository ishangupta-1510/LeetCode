class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        vector<bool>dp(s.length()+1,false);
        dp[0] = true;
        set<string> se;
        for(int i=0;i<n;i++){
            se.insert(wordDict[i]);
        }
        for(int i=1;i<=s.length();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(se.find(s.substr(j,i-j)) != se.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};