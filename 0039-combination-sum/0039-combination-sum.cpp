class Solution {
public:
    void comb(int i,int target,vector<int>& v,vector<vector<int>>& vec,vector<int> &candidates){
        if(i>=candidates.size()){
            if(target == 0){
                vec.push_back(v);
            }
            return;
        }
        if(candidates[i] <= target){
            v.push_back(candidates[i]);
            comb(i,target-candidates[i],v,vec,candidates);
            v.pop_back();
        }
        comb(i+1,target,v,vec,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        vector<int> v;
        comb(0,target,v,vec,candidates);
        return vec;
    }
};