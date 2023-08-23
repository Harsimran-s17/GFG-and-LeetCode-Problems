//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
    //     // Your code here
      

    // // The number of jumps needed to
    // // reach the starting index is 0
    // if (n <= 1)
    //     return 0;

    // // Return -1 if not possible to jump
    // if (arr[0] == 0)
    //     return -1;

    // // initialization
    // // stores all time the maximal
    // // reachable index in the array.
    // int maxReach = arr[0];

    // // stores the number of steps
    // // we can still take
    // int step = arr[0];

    // // stores the number of jumps
    // // necessary to reach that maximal
    // // reachable position.
    // int jump = 1;

    // // Start traversing array
    // int i = 1;
    // for (i = 1; i < n; i++) {
    //     // Check if we have reached the end of the array
    //     if (i == n - 1)
    //         return jump;

    //     // updating maxReach
    //     maxReach = max(maxReach, i + arr[i]);

    //     // we use a step to get to the current index
    //     step--;

    //     // If no further steps left
    //     if (step == 0) {
    //         // we must have used a jump
    //         jump++;

    //         // Check if the current index/position or lesser index
    //         // is the maximum reach point from the previous indexes
    //         if (i >= maxReach)
    //             return -1;

    //         // re-initialize the steps to the amount
    //         // of steps to reach maxReach from position i.
    //         step = maxReach - i;
    //     }
    // }
    
    
    
    
    
    int maxreach = 0;
    int steps = arr[0];
    
    if(n <= 1) return 0;
    if(arr[0] == 0) return -1;
    
    int jump = 1;
    
    for(int i = 1; i < n; i++){
        
        if(i == n-1) return jump;
        
        maxreach = max(maxreach, i + arr[i]);
        
        steps--;
        
        if(steps == 0){
            jump++;
            
            if(maxreach == i) return -1;
            steps = maxreach - i;
            
            maxreach = 0;
        }
    }
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends