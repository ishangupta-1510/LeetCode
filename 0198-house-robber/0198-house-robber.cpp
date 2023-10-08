class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1){
                pick += dp[i-2];
            }
            int nonpick = dp[i-1];
            cout<<pick<<" "<<nonpick<<endl;
            dp[i] = max(pick,nonpick);
        }
        return dp[n-1];
    }
};