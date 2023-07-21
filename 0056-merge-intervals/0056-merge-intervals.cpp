class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0] == b[0]){
            return a[1]<b[1];
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int i=0;
        int n = intervals.size();
        vector<vector<int>> v;
        if(n == 1){
            v.push_back(intervals[0]);
        }
        while(i<n-1){
            int j = i+1;
            while(j<n){
                if(intervals[i][1]>=intervals[j][0]){
                    intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                }
                else{
                    break;
                }
                j++;
            }
            v.push_back(intervals[i]);
            i=j;
        }
        if(intervals[n-1][1] > v[v.size()-1][1]){
            v.push_back(intervals[n-1]);
        }
        return v;
    }
};