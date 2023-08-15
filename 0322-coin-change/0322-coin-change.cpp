class Solution {
public:
    int dp(vector<int>& coins,int amount,int i,vector<vector<int>>& v){

        // cout<<amount<<"  "<<index<<" "<<endl;
        if(v[i][amount] != -1){
            return v[i][amount];
        }
        if(amount == 0){
            return 0;
        }
        if(i>coins.size()-1 || amount<0){
            return INT_MAX-1;
        }
        int dotake = INT_MAX-1;
        int dont = INT_MAX-1;
        if(coins[i]>amount) {
            dont = 0+dp(coins,amount,i+1,v);
        }
        else{
            dotake = 1+dp(coins,amount-coins[i],i,v);
            dont = 0+dp(coins,amount,i+1,v);
        }
        // cout<<"returned "<<amount<<"  "<<index<<" "<<min(take,notTake)<<endl;
        return v[i][amount] = min(dotake,dont);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> v(n+1,vector<int>(amount+1,-1));
        int k = dp(coins,amount,0,v);
        return k == INT_MAX-1 ? -1:k;
    }
};
