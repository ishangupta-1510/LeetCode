class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        map<string,char> c;
        vector<string> v;
        stringstream str(s);
        string word;
        while(str >> word){
            v.push_back(word);
        }
        int n = v.size(), ms = pattern.size();
        if(n != ms){
            return false;
        }
        for(int i=0;i<n;i++){
            if(m.find(pattern[i]) == m.end() and c.find(v[i]) == c.end()){
                m[pattern[i]] = v[i];
                c[v[i]] = pattern[i];
            }
            else if(m[pattern[i]] != v[i] and c[v[i]] != pattern[i]){
                return false;
            }
        }
        return true;
    }
};
