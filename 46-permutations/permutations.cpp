class Solution {
public:
    void permute(vector<int> a,int n,vector<vector<int>> &vec, map<int,int>& m,vector<int>& v){
        if(v.size() == n){
            vec.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(m[a[i]] == 0){
                v.push_back(a[i]);
                m[a[i]] = 1;
                permute(a,n,vec,m,v);
                m[a[i]] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec;
        map<int,int> m;
        vector<int> v;
        permute(nums,n,vec,m,v);
        return vec;
    }
};