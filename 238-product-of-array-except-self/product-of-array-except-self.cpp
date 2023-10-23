class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                count++;
                continue;
            }
            else{
                prod *= nums[i];
            }
        }
        if(count == 0){
            for(int i=0;i<n;i++)
                nums[i] = prod/nums[i];
        }
        else if(count == 1){
            for(int i=0;i<n;i++){
                if(nums[i] == 0){
                    nums[i] = prod;
                }
                else{
                    nums[i] = 0;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                nums[i] = 0;
            }
        }
        return nums;
    }
};