//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int lesserElements(vector<int> vec, int ele){
        int low = 0;
        int n = vec.size();
        int high = n - 1;
        
        while(low<=high){
            int mid = (low+high)>>1;
            if(vec[mid]<= ele) low = mid+1;
            else high = mid - 1;
        }
        return low;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here      
        int low = 1;
        int high = 2000;
        int m = (R*C)>>1;
        
        while(low<=high){
            int mid = (low+high)>>1;
            int count = 0;
            
            for(int i = 0; i < R; i++){
              count+= lesserElements(matrix[i],mid); 
            }
            
            if(count<=m) low = mid+1;
            else high = mid - 1;
            
        }
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends