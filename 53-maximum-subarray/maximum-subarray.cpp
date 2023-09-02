class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,msum=0,flag = 1,mine = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                flag = 0;
            }
            if(sum<0){
                sum = 0;
            }
            sum += nums[i];
            msum = max(sum,msum);
            
        }
        if(flag == 1){
            for(int i=0;i<n;i++){
                mine = max(mine,nums[i]);
            }
            return mine;
        }
        return msum;
    }
};