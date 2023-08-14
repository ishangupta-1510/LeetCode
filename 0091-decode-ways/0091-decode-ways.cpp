class Solution {
public:
    int Choices(string s, int index, vector<int> &dp){
        if(index == s.size()){
            return 1;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int res = 0;
        if(s[index] != '0'){
            res += Choices(s,index+1,dp);
        }
        if(index + 1 <s.size() and (s[index] == '1' or (s[index] == '2' and s[index+1] <= '6'))){
            res += Choices(s, index+2,dp);

        }
        return dp[index] = res;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return Choices(s,0,dp);
    }
};