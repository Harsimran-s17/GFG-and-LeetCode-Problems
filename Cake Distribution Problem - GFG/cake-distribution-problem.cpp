//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& arr, int N, int K) {
    // Write your code here.
    int low = 1;
    int high = pow(10,9);
    int ans;
    
    while(low<=high){
        int mid = (low+high)>>1;
        
        int sum = 0;
        int count = 0;
        bool flag = false;
        
        for(int i = 0; i < N; i++){
            if(arr[i] + sum == mid){
                flag = true;
                count++;
                sum = 0;
            }
            else if(sum+arr[i]>mid){
                count++;
                sum = 0;
            }
            else sum += arr[i];
        }
        
        if(count >= K + 1) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends