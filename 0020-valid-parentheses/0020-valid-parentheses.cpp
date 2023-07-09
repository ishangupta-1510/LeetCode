class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        if(n%2){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(abs(s[i]-st.top())>2){
                    return false;
                }
                st.pop();
            }
            
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};