class Solution {
public:
    pair<int,int> helper(string &s, int p, int q)
    {
        while(p>=0 && q<s.length() && s[p] == s[q])
        {
            p--;
            q++;
        }
        return {p+1,q-1};
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 1,l=0,r=0;
        
        for(int i=1;i<n;i++)
        {
            pair<int,int> p1 = helper(s,i,i);
            pair<int,int> p2 = helper(s,i,i-1);
            if(p1.second-p1.first+1 > ans)
            {
                ans = p1.second-p1.first+1;
                l = p1.first;
                r = p1.second;
            }
            if(p2.second-p2.first+1 > ans)
            {
                ans = p2.second-p2.first+1;
                l = p2.first;
                r = p2.second;
            }
        }
        string str = "";
        for(int i=l;i<=r;i++)
            str += s[i];
        return str;
    }
};