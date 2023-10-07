class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> m;
        int n = strs.size();
        vector<string> v = strs;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            sort(strs[i].begin(),strs[i].end());
        }
        for(int  i=0;i<n;i++){
            m[strs[i]].push_back(i);
        }
        for(auto& x:m){
            vector<string> temp;
            for(int i=0;i<x.second.size();i++){
                temp.push_back(v[x.second[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};