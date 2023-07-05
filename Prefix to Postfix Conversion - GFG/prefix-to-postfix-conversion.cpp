//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        string ans = "";
        stack<string> st;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '+'){
                string str = "";
                str += st.top();
                st.pop();
                str += st.top();
                st.pop();
                str += s[i];
                st.push(str);
            }
            else{
                string ch(1,s[i]);
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans+= st.top();
            st.pop();
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends