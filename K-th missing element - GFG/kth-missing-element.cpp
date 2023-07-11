//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int arr[], int n, int k)
{
    // Complete the function
    int c = 0;
    
    for(int i = 1; i < n; i++){
        if(arr[i]-arr[i-1] == 1) continue;
        else{
            if(arr[i]-arr[i-1] + c<k+1) c += arr[i] -arr[i-1] - 1;
            else{
                while(c<k){
                    arr[i-1]++;
                    c++;
                }
                return arr[i-1];
            }
        }
    }
    
    return -1;
}