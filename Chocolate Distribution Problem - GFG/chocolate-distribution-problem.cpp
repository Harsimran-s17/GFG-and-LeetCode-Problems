//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
    //code
    sort(arr.begin(), arr.end());
    long long ans = LONG_MAX;
    
    if(m>n) return -1;
    
    
    
    int i = 0;
    int j = m-1;
    
    while(j < n){
        ans = min(ans, arr[j] - arr[i]);
        j++; i++;
    }
    
    return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends