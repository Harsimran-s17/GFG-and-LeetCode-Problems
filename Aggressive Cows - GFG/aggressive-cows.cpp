//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int ans = 0;
        int low = 1;
        int high = 1000000000;
        
        sort(stalls.begin(), stalls.end());
        
        while(low <= high){
            int mid = (low+high)>>1;
            int count = 1;
            int last = stalls[0];
            
            for(int i = 1; i < n; i++){
                if(stalls[i] - last >= mid){
                    count++;
                    last = stalls[i];
                }
            }
            
            if(count >= k){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends