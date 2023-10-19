class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] = nums[i] + nums[i-1];
        }
        for(int i=0;i<n;i++){
            presum.push_back(nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return presum[right];
        }
        return presum[right] - presum[left-1];
    }
private:
    vector<int> presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */