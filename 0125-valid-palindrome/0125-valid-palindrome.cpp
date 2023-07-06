class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' and s[i]<='Z'){
                s[i] = s[i]-'A'+'a';
            }
        }
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9')){
                str.push_back(s[i]);
            }
        }
        cout<<str;
        int start = 0,end=str.length()-1;
        while(start<=end){
            if(str[start] != str[end]){
                // cout<<start<<" "<<end<<endl;
                // cout<<s[start]<<" "<<s[end];
                return false;
            }
            start++;end--;
        }
        return true;
    }
};