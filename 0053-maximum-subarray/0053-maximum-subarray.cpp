class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN;
        int flag = 0;
        int ssum=0,msum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                m = max(m,nums[i]);
            }
            if(nums[i] == 0){
                flag = 1;
            }
            ssum += nums[i];
            if(ssum>msum){
                msum = ssum;
            }
            if(ssum<0){
                ssum = 0;
            }
        }
        if(msum == 0 and flag==0){
            return m;
        }
        return msum;
    }
};