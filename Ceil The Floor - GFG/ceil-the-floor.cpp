//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    int start = 0, end = n-1;
    int mid=0,ans1=-1, ans2=-1;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]<x){
            start=mid+1;
        }
        else if(arr[mid]>x){
            end = mid-1;
        }
        if(arr[mid] == x){
            ans1 = mid;
            ans2 = mid;
            return {arr[ans2],arr[ans1]};
        }
        
    }
    (start == n)?(ans1=-1):(ans1=arr[start]);
    (end == -1)?(ans2=-1):(ans2=arr[end]);
    return {ans2,ans1};
    
}