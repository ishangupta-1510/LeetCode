class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        map<int,int> m;
        int count = 1,maxcount=1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = 1;
        }
        for(int i=0;i<nums.size();i++){
            if(!m[nums[i]-1]){
                int j = nums[i];
                while(m[j]){
                    j++;
                }
                count = max(count,j-nums[i]);
            }
            
        }
        return count;
    }
};