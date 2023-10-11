class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int len = 0, start = 0;
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            len = 1;
            start = i;
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                len = 2;
                start = i;
            }
        }
        
        for(int j=2;j<n;j++){
            for(int i=0;i<n-j+1;i++){
                if(dp[i+1][j+i-1] and s[i] == s[j+i]){
                    dp[i][j+i] = 1;
                    len = j+1;
                    start = i;
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};