class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
//         unordered_map<int , int > m;
//         int N = arr.size();
//       for(int i = 0; i < N; i++)
//         m[arr[i]] = 1;
        
//         int ans = 0;
        
//         for(int i = 0; i < N; i++){
//             int count = 0;
//             int t = arr[i];
//             if(!m[t-1]){
//                 while(m[t]){
//                     count++;
//                     t++;
//                 }
//                 ans = max(ans,count);
//             }
//         }
//         return ans;
//     }
        
        unordered_map<int,int> m;
        int n = arr.size();
        
        for(int i =0; i < n;i++){
            m[arr[i]] = 1;
        }
        
        int count = 0; 
        int ans = 0;
        
         for(int i = 0; i < n; i++){
             if(!m[arr[i] - 1]){
                 int k = arr[i];
                 while(m[k]){
                     count++;
                     k++;
                 }
                 }
                 ans = max(ans,count);
                 count  = 0;
             }
        return ans;
    }
};