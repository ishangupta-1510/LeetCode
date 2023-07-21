class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prevend = intervals[0][1];
        int n = intervals.size();
        int res = 0;
        for(int i=1;i<n;i++){
            if(prevend <= intervals[i][0]){
                prevend = intervals[i][1];
            }
            else{
                res++;
                prevend = min(intervals[i][1],prevend);
            }
        }
        return res;
    }
};