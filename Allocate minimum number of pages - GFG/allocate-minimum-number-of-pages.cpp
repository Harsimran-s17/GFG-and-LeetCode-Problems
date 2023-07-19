//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        
        if(m>n) return -1;
        
        int high = 0;
        
        for(int i = 0; i < n; i++){
            high += arr[i];
        }
        
        int low = 0;
        int ans = -1;
        
        while(low<=high){
            int mid = (low+high)>>1;
            int count = 0;
            int sum = 0;
            
            for(int i = 0; i < n; i++){
                if(arr[i] > mid){
                    count = m+1;
                    break;
                }
                if(sum + arr[i] > mid){
                    count++;
                    sum = arr[i];
                }
                else{
                    sum += arr[i];
                }
            }
            count++;
            if(count <= m){
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends