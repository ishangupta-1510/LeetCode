class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end =nums.size();
        if(nums[0]<=nums[end-1]){
            return nums[0];
        }
        int m=INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            m = min(m,nums[mid]);
            if(nums[mid]>=nums[0]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return m;
    }
};