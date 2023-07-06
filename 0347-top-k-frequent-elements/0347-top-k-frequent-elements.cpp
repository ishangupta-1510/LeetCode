class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        vector<pair<int,int>> vec(m.begin(),m.end());
        sort(vec.begin(),vec.end(),comp);
        vector<int> v;
        for(int i=0;i<k;i++){
            v.push_back(vec[i].first);
        }
        return v;
    }
};