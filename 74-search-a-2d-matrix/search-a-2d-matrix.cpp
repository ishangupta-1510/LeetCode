class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0,end=matrix.size()-1, e = matrix[0].size()-1,s=0;
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[mid][0] <= target and matrix[mid][e] >= target){
                while(s<=e){
                    int m = (s+e)/2;
                    if(matrix[mid][m] == target){
                        return true;
                    }
                    else if(matrix[mid][m] < target){
                        s = m+1;
                    }
                    else{
                        e = m-1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
};