class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums.size();
        vector<int> a(s);
        int k;
        for(int i=0;i<s;i++){
            a[nums[i]] += 1;
            if(a[nums[i]] == 2){
                k = nums[i];
                break;
            }
        }
        return k;
    }
};