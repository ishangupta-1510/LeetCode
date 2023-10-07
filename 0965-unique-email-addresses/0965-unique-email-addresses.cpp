class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,int> m;
        int n = emails.size();
        int count = 0;
        for(int i=0;i<n;i++){
            string s;
            int k = 0;
            bool skip = false;
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j] == '@'){
                    // cout<<'runnign';
                    skip = false;
                    k = 1;
                }
                if(emails[i][j] == '+' and k == 0){
                    skip = true;
                    continue;
                }
                if((emails[i][j] != '.' or k == 1) and !skip){
                    // cout<<i<<" "<<j<<' '<<k<<endl;
                    s += emails[i][j];
                }
            }
            cout<<s<<endl;
            if(!m[s]){
                count++;
                m[s]++;
            }
        }
        return count;
    }
};