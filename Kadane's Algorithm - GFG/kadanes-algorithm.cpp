//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        // long long sum = arr[0];
        // long long ans = arr[0];
        // for(int i = 1; i < n; i++){
        //     sum += arr[i];
        //     if(sum  < arr[i]) sum = arr[i];
        //     if(sum > ans) ans = sum;
        // }
        // return ans;
        
        
        
        long long sum = INT_MIN;
        long long ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(sum < 0 && arr[i] > sum){
                sum = arr[i];
            }else{
                sum += arr[i];
            }
            if(ans < sum) ans = sum;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends