class Solution {
public:
    int tarsum(vector<int>& nums,int target,int i){
        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        return tarsum(nums,target*-1+nums[i],i+1)  +  tarsum(nums,target+nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return tarsum(nums,target,0);
    }
};