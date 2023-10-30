class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int m = prices[n-1];
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            m = max(m,prices[i]);
            ans = max(ans,m-prices[i]);
        }
        return ans;
    }
};