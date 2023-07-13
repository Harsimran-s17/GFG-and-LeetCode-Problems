//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int k, vector<int> &bloomDay){
      // Code here
      
      int n = bloomDay.size();
      if((long long)k*m > n) return -1;
      int ans = INT_MAX;
      
      int high = -1;
      for(auto i : bloomDay) high = max(i, high);
      
      int low = 1;
      
      while(low <= high){
          int j = 0;
          int count = 0;
          int mid = (low+high)>>1;
          
            int c = 0;
            while(j<n){
                if(bloomDay[j]>mid){
                    c=0;
                }
                else c++;
                if(c == k) {
                    c=0; 
                    count++;
                }
                j++;
            }

          if(count>=m){
              ans = min(ans, mid);
              high = mid - 1;
          }
          else{
              low = mid+1;
          }
      }
      
      return ans;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends