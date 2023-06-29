//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int rec(int arr[],int n,vector<int>&dp){
        if(n==0){
            return arr[0];
        }
        if(n<0){
            return 0;
        }
        if(~dp[n]){
            return dp[n];
        }
        int take = arr[n]+rec(arr,n-2,dp);
        int nottake = 0+rec(arr,n-1,dp);
        return dp[n] = max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+1,-1);
        return rec(arr,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends