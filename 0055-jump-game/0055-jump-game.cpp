class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int p=nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            p = max(p-1,nums[i]);
            if(p==0 and i!=n-1){
                return false;
            }
        }
        return true;
    }
};