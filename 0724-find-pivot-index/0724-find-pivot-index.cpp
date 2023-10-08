class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot_sum = 0, cur_sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            tot_sum += nums[i];
        }
        for(int i=0;i<n;i++){
            cur_sum += nums[i];
            if(tot_sum+nums[i] == 2*cur_sum){
                return i;
            }
        }
        return -1;
    }
};