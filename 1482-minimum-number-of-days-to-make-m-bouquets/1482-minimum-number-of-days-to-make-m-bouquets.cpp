class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
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