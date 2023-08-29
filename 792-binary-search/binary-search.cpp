class Solution {
public:
    bool mono(int mid,vector<int> nums,int target){
        if(nums[mid]<target){
            return true;
        }
        return false;
    }
    int search(vector<int>& nums, int target) {
        int start = 0,end=nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(mono(mid,nums,target)){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};