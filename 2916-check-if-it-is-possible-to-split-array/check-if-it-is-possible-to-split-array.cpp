class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n<3){
            return true;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]+nums[i+1]>=m){
                return true;
            }
        }
        return false;
    }
};