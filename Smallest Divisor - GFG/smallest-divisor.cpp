//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n = nums.size();
        
        int low = 1;
        int  high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = (low+high)>>1;
            int count = 0;
            for(int i = 0; i < n; i++){
                count += nums[i]/mid;
                if(nums[i]%mid) count++;
            }
            if(count<=K){
                ans = min(ans, mid);
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        return low;
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
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends