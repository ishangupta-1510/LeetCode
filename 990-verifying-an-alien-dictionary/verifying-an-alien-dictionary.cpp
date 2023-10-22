class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,char> m;
        for(int i=0;i<26;i++){
            m[order[i]] = i + 'a';
        }
        for(string &x: words){
            for(char &c: x){
                c = m[c];
            }
        }
        return is_sorted(words.begin(),words.end());
    }
};