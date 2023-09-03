class Solution {
public:
    bool partition(vector<int>& nums,int n,int sum,vector<vector<int>>& dp){
        // cout<<n<<" "<<sum<<endl;
        if(n <= 0){
            if(sum == 0){
                return true;
            }
            return false;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int take  = 0,nottake=0;
        if(sum>=nums[n]){
            take = partition(nums,n-1,sum-nums[n],dp);
        }
        nottake = partition(nums,n-1,sum,dp);
        return dp[n][sum] = take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return partition(nums,n-1,sum/2,dp);
    }
};