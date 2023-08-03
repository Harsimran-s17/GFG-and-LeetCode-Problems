//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void reverseArr(vector<int> &arr, int s, int e){
        while(s<e) {swap(arr[e--], arr[s++]);}
    }
    
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int i;
        for(i = n-1; i > 0; i--){
            if(arr[i]>arr[i-1]) break;
        }
        
        if(i!=0){
            int j = n-1;
            while(arr[i-1]>=arr[j] && j>i-1)j--;
            
            swap(arr[i-1],arr[j]);
            
        }
            reverseArr(arr, i, n-1);
            return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends