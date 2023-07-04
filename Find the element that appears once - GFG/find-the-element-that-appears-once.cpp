//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    int low = 0;
	    int high = n-1;
	    
	    while(low<=high){
	        int mid = (low+high)>>1;
	        if(mid%2){
	            if(arr[mid] == arr[mid -1])low = mid + 1;
	            else if(arr[mid] == arr[mid+1]) high  = mid - 1;
	            else return arr[mid];
	        }
	        else{
	            if(mid != 0 && arr[mid] == arr[mid-1]) high = mid -1;
	            else if(mid != n-1 && arr[mid] == arr[mid + 1]) low = mid + 1;
	            else return arr[mid];
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends