//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        string ans = "";
        stack<char> st;
        
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '+'){
                st.push(')');
                st.push(s[i]);
                ans += '(';
            }
            else{
                char ch = st.top();
                ans += s[i];
                
                  while(ch == ')'){
                      ans+= ch;
                      st.pop();
                      if(st.empty()) break;
                      ch = st.top();
                  } 
                
                // For adding operator after closing all the braces
                if(!st.empty()){
                ans += ch;
                st.pop();
                    
                }
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends