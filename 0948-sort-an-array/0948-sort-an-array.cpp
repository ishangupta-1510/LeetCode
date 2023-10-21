class Solution {
public:
    void merge(vector<int>& nums,int start,int mid,int end){
        int p1 = start, p2 = mid+1;
        vector<int> ans;
        while(p1 <= mid and p2 <= end){
            if(nums[p2] < nums[p1]){
                ans.push_back(nums[p2]);
                p2++;
            }
            else{
                ans.push_back(nums[p1]);
                p1++;
            }
        }
        while(p1<=mid){
            ans.push_back(nums[p1]);
            p1++;
        }
        while(p2<=end){
            ans.push_back(nums[p2]);
            p2++;
        }
        for (int i = start, j = 0; i <= end; i++, j++) {
            nums[i] = ans[j];
        }
    }
    void mergesort(vector<int>& nums,int start,int end){
        int mid = (start+end)/2;
        if(start >= end){
            return;
        }
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};