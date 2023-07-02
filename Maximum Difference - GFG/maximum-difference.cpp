//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      stack<int> left;
      stack<int> temp;
      vector<int> vec;
      
      for(int i = 0;  i < n; i++){
          if(temp.empty()) left.push(0);
          else{
              while(!temp.empty() && temp.top()>=A[i]){
                  vec.push_back(temp.top());
                  temp.pop();
              }
              if(temp.empty()) left.push(0);
              else{
                  left.push(temp.top());
                  }
          }
        temp.push(A[i]);
      }
      while(!temp.empty()) temp.pop();
      vec.clear();
      stack<int> right;
      
      for(int i = n-1; i>=0; i--){
          if(temp.empty()) right.push(0);
          else{
              while(!temp.empty() && temp.top()>=A[i]){
                  vec.push_back(temp.top());
                  temp.pop();
              }
              if(temp.empty()) right.push(0);
              else{
                  right.push(temp.top());
                  }
          }
        temp.push(A[i]);
      }
      while(!temp.empty()) temp.pop();
      
      while(!right.empty()){
          temp.push(right.top());
          right.pop();
      }
      
      int ans = 0;
      
      for(int i = 0; i < n; i++){
        //   cout<<temp.top()<<" ";
          ans = max(ans, abs(left.top() - temp.top()));
        //   cout<<left.top()<<" "<<temp.top()<<endl;
          left.pop();
          temp.pop();
      }
      
      
      
      return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends