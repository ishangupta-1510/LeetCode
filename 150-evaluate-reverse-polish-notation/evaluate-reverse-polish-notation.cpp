class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s1;
        int n = t.size();
        for(int i=0;i<n;i++){
            if(t[i] == "+" || t[i] == "-" || t[i] == "*" || t[i] == "/"){
                int first = s1.top();
                s1.pop();
                int second = s1.top();
                s1.pop();
                if(t[i] == "+") first = first + second;
                if(t[i] == "-") first = second - first;
                if(t[i] == "*") first = first * second;
                if(t[i] == "/") first = second / first;
                s1.push(first);
            }
            else{
                s1.push(stoi(t[i]));
            }
        }
        return s1.top();
    }
};