class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX;
        int p = INT_MIN;
        for(int i=0;i<prices.size();i++){
            m = min(m,prices[i]);
            p = max(p,prices[i]-m);
        }
        return p;
    }
};