//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	   // int l = 0; int h = n -1;
	   // int mid;
	   // int count = 1;
	   // while(l<=h){
	   //     mid = (l+h)/2;
	   //     if(arr[mid]==x){
	   //         int i = mid-1, j = mid +1;
	   //         while(  (arr[i] == x || arr[j] == x)){
	   //             if(arr[i] == x) count++;
	   //             if(arr[j] == x) count++;
	   //             i--;j++;
	   //         }
	   //         return count;
	   //     }
	   //     if(arr[mid]>x) h = mid -1;
	   //     else l = mid + 1;
	   // }
	    
	   // return 0;
	   
	   //OR
	   
	   int low = 0;
	   int high = n - 1;
	   int s = 1;   // set to 1 because if no element found it should return 0+1-1 = 0
	   while (low <=high){
	       int mid = (low+high)>>1;
	       
	       if(arr[mid] == x){
	           s = mid;
	           high = mid - 1;
	       }
	       else if(arr[mid] > x) high = mid - 1;
	       else low = mid + 1;
	   }
	   int e = 0;
	   low = 0; high = n-1;
	   while (low <=high){
	       int mid = (low+high)>>1;
	       
	       if(arr[mid] == x){
	           e = mid;
	           low = mid + 1;
	       }
	       else if(arr[mid] > x) high = mid - 1;
	       else low = mid + 1;
	   }
	   return (e-s+1);
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends