//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        
        int low = 1;
        int high = sum;
        int ans = INT_MAX;
        
        while(low <= high){
            int mid = (low+high)>>1;
            int count = 0;
            int s = 0;
            for(int i = 0; i < N; i++){
                if(arr[i]>mid){
                    count = D +1;
                    break;
                }
                s+=arr[i];
                if(s == mid) {
                    count++;
                    s = 0;
                }
                else if(s>mid){
                    count++;
                    s = arr[i];
                }
            }
            if(s)count++;
            
            if(count <= D) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends