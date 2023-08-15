class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1,curMin = 1;
        int res = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            int temp = curMax;
            curMax = max(max(curMax*nums[i],curMin*nums[i]),nums[i]);
            curMin = min(min(temp*nums[i],curMin*nums[i]),nums[i]);
            res = max(res,curMax);
        }
        return res;
    }
};