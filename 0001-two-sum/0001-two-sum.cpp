class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m[target-nums[i]]){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]-1);
                break;
            }
            m[nums[i]] = i+1;
        }
        return ans;
    }
};