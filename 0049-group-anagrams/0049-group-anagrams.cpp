class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> s = strs;
        map<string,vector<string>> m;
        for(int i=0;i<s.size();i++){
            sort(s[i].begin(),s[i].end());
        }
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(strs[i]);
        }
        vector<vector<string>> v;
        string k = "aet";
        
        cout<<endl;
        vector<string> temp;
        temp.push_back("0");
        for(auto x:s){
            if(m[x] != temp){
                v.push_back(m[x]);

                m[x] = temp;
            }
            
        }
        return v;
    }
};