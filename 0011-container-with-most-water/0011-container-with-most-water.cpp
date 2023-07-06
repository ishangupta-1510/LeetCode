class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0,end = height.size()-1;
        int maxh = 0;
        while(start<end){
            maxh = max(maxh,min(height[end],height[start])*(end-start));
            if(height[start]<height[end]){
                // cout<<start<<" "<<end;
                // cout<<"use";
                start++;
            }
            else{
                end--;
            }
            // cout<<end<<" "<<start<<endl;
            
        }
        return maxh;
    }
};