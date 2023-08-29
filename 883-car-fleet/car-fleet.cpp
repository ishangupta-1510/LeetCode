class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int n = speed.size();
        for(int i=0;i<n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());
        int fleet = 1;
        float temp = INT_MIN;
        for(int i=n-1;i>0;i--){
            float t1 = static_cast<float>(target-vec[i].first)/vec[i].second;
            float t2 = static_cast<float>(target-vec[i-1].first)/vec[i-1].second;
            if(t1<temp){
                t1 = temp;
            }
            cout<<t1<<" "<<t2<<endl;
            if(t2>t1){
                fleet++;
            }
            else{
                temp = t1;
            }
        }
        return fleet;
    }
};