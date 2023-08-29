class Solution {
public:
    bool isValid(string s,int n){
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] == ')' and st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
    void allComb(string s,vector<string>& v,int n){
        if(s.size() == 2*n){
            if(isValid(s,2*n)){
                v.push_back(s);
            }
            return;
        }
        s.push_back('(');
        allComb(s,v,n);
        s.pop_back();
        s.push_back(')');
        allComb(s,v,n);
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> v;
        allComb(s,v,n);
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        return v;
    }
};