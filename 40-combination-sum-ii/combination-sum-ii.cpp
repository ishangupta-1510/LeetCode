class Solution {
public:
    void targetsum(vector<vector<int>> &v,vector<int> &vec,vector<int>& c,int target,int i){
        if(i==c.size()){
            if(target == 0){
                // sort(vec.begin(),vec.end());
                v.push_back(vec);
            }
            return;
        }
        if(c[i]<=target){
            vec.push_back(c[i]);
            targetsum(v,vec,c,target-c[i],i+1);
            vec.pop_back();
        }
        while (i + 1 < c.size() && c[i] == c[i + 1]) {
            i++;
        }
        targetsum(v,vec,c,target,i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        targetsum(v,vec,candidates,target,0);
        return v;
    }
};