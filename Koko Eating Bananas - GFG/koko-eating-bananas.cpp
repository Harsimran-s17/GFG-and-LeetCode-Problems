//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = (low+high)>>1;
            int count = 0;
            for(int i = 0; i < N; i++){
                count += piles[i]/mid;
                if(piles[i]%mid) count++; 
            }
            if(count<=H){
               ans = min(ans,mid);
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends