class Solution {
public:
    void subset(vector<int>& nums,int i,int n,vector<int>& v,vector<vector<int>>& vec){
        if(i >= n){
            vec.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        subset(nums,i+1,n,v,vec);
        v.pop_back();
        subset(nums,i+1,n,v,vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> vec;
        subset(nums,0,nums.size(),v,vec);
        return vec;
    }
};