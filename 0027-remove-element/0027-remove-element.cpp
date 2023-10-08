class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> v;
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != val){
                count++;
                v.push_back(nums[i]);
            }
        }
        for(int i=0;i<v.size();i++){
            nums[i] = v[i];
        }
        return count;
    }
};