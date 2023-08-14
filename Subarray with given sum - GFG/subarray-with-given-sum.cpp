//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
          long long sum = 0;
        int st = 0; 
        vector<int> vec;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            while(sum > s && st < i){
                sum -= arr[st];
                st++;
            }
            if(sum==s){
                vec.push_back(st+1);
                vec.push_back(i+1);
                break;
            }
        }
        if(vec.size()<2) vec.push_back(-1);
        return vec;
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends