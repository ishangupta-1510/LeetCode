class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row,col;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int j=0;j<row.size();j++){
            for(int i=0;i<m;i++){
                matrix[row[j]][i] = 0;
            }
        }
        for(int j=0;j<col.size();j++){
            for(int i=0;i<n;i++){
                matrix[i][col[j]] = 0;
            }
        }
    }
};