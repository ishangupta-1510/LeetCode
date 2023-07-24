class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i=0;i<n;i++){
            k = k^i^nums[i];
        }
        k = k^(n);
        return k;
    }
};