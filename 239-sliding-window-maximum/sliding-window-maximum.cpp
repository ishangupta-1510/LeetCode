class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i >= k and !dq.empty() and dq.front() == i-k){
                dq.pop_front();
            }
            while(!dq.empty() and nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};