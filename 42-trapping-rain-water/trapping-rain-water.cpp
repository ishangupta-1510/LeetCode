class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = -1;
        int rmax = -1;
        vector<int> vl,vr;
        int n = height.size();
        for(int i=0;i<n;i++){
            if(height[i] > lmax){
                lmax = height[i];
                vl.push_back(-1);
            }
            else{
                vl.push_back(lmax);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(height[i] > rmax){
                rmax = height[i];
                vr.push_back(-1);
            }
            else{
                vr.push_back(rmax);
            }
        }
        reverse(vr.begin(),vr.end());
        for(int i=0;i<n;i++){
            cout<<vl[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<vr[i]<<" ";
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int k = min(vr[i],vl[i]);
            if(k!=-1){
                ans += k-height[i];
            }
        }
        return ans;
    }
};