class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        int n = nums1.size(), p = nums2.size();
        for(int i=0;i<p;i++){
            m[nums2[i]] = i;
        }
        stack<int> s;
        for(int i=p-1;i>=0;i--){
            if(!s.empty()){
                while(!s.empty() and s.top() < nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(nums2[i]);
                    nums2[i] = -1;
                }
                else{
                    int temp = nums2[i];      
                    nums2[i] = s.top();
                    s.push(temp);
                }
            }
            else{
                s.push(nums2[i]);
                nums2[i] = -1;
            }
        }
        for(int i=0;i<p;i++){
            cout<<nums2[i]<<" ";
        }
        for(int i=0;i<n;i++){
            // cout<<"ran";
            nums1[i] = nums2[m[nums1[i]]];
        }
        return nums1;
    }
};