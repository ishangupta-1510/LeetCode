class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(m[nums[i]] > 0){
                return true;
            }
            m[nums[i]]++;
        }
        return false;
    }
};