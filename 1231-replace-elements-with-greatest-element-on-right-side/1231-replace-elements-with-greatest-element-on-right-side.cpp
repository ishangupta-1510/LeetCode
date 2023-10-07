class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int g = INT_MIN;
        int n = arr.size();
        vector<int> ans(n);
        for(int i=n-2;i>=0;i--){
            g = max(g,arr[i+1]);
            ans[i] = g;
        }
        ans[n-1] = -1;
        return ans;
    }
};