class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        int countzero = 0;
        int multiply = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                multiply *= nums[i];
            }
            else{
                countzero++;
            }
        }
        if(countzero>1){
            for(int i=0;i<nums.size();i++){
                v.push_back(0);
            }
        }
        else{
            if(countzero == 1){
                for(int i=0;i<nums.size();i++){
                    if(nums[i] != 0){
                        v.push_back(0);
                    }
                    else{
                        v.push_back(multiply);
                    }
                }
            }
            else{
                for(int i=0;i<nums.size();i++){
                    v.push_back(multiply/nums[i]);
                }
            }
        }

        return v;
    }
};