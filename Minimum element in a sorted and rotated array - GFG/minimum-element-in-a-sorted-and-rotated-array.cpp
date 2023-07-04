//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int findMin(int arr[], int n){
        //complete the function here
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        
        while(low <= high){
            int mid = (low+high)>>1;
            if(arr[mid]<arr[low]){
                ans = min(arr[mid],ans);
                high = mid -1;
            }
            else{
                ans = min(arr[low],ans);
                low = mid + 1;
            }
            
        }
        return ans;
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
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends