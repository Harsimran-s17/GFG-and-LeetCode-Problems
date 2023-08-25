//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
// 	int isPal(string S, int start, int end){
// 	    if(start < end){
// 	        if(!isPal(S, start  + 1, end  - 1)) return 0;
// 	        if(S[start] != S[end]){
// 	            return 0;
// 	        }
// 	        return 1;
// 	    }else{
// 	        return 1;
// 	    }
// 	}
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	   // int n = S.length();
	   //  return isPal(S, 0 , n -1);
	    int l = 0;
    int h = S.length() - 1;
 
    // Keep comparing characters
    // while they are same
    while (h > l) {
        if (S[l++] != S[h--]) {
            return 0;
            // will return from here
        }
    }
	 return 1;   
	}

};


//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends