//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int rec(vector<vector<int>>& points, int n,int k,vector<vector<int>>& dp){
        if(n<=0){
            return 0;
        }
        int ans = 0;
        int maxi = 0;
        if(~dp[n][k]){
            return dp[n][k];
        }
        for(int i=0;i<3;i++){
            if(k!=i){
                ans = points[n-1][i] + rec(points,n-1,i,dp);
                // cout<<points[n-1][i]<<" "<<n-1<<" "<<i<<" "<<maxi<<" "<<ans<<endl;
                maxi = max(ans,maxi);
            }
        }
        return dp[n][k] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return rec(points,n,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends