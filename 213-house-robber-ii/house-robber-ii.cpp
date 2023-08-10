class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }

        // Calculate maximum if first house is robbed and last house is not robbed
        vector<int> dp1(n, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        // Calculate maximum if last house is robbed and first house is not robbed
        vector<int> dp2(n, 0);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        // Return the maximum of the two scenarios
        return max(dp1[n - 2], dp2[n - 1]);
    }
};
