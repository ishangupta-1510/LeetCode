class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start = 0,end = matrix.size();
        vector<int> v;
        int n = matrix[0].size();
        int k = end * n;
        while(start <= min(n/2,end/2)){
            for(int i=start;i<n-start;i++){
                if(v.size()<k){
                    v.push_back(matrix[start][i]);
                }
            }
            for(int i=start+1;i<end-start;i++){
                if(v.size()<k){
                    v.push_back(matrix[i][n-start-1]);
                }
            }
            for(int i=n-start-2;i>=start;i--){
                if(v.size()<k){
                    v.push_back(matrix[end-start-1][i]);
                }
            }
            for(int i=end-start-2;i>start;i--){
                if(v.size()<k){
                    v.push_back(matrix[i][start]);
                }
            }
            start++;
        }
        return v;
    }
};