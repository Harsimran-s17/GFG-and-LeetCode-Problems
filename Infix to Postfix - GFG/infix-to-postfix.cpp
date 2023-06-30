//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<pair<char,int>> st;
        string ans = "";
        unordered_map<char,int> m;
        m['+'] = 1;
        m['-'] = 1;
        m['/'] = 2;
        m['*'] = 2;
        m['^'] = 3;
        m['('] = 0;
        
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >='0' && s[i] <= '9'){
                ans+= s[i];
            }
            else{
                if(st.empty()) st.push({s[i],m[s[i]]});
                else{
                    if(s[i] == '(')st.push({s[i], 0});
                    else if(s[i]==')'){
                        while(st.top().second!=0){
                        char temp  = st.top().first;
                        st.pop();
                        ans += temp;
                        }
                        st.pop();
                    }
                    else if(st.top().second >= m[s[i]]){
                        while(!st.empty() && st.top().second >= m[s[i]]&& st.top().second!=0){
                        char temp  = st.top().first;
                        st.pop();
                        ans += temp;
                    }
                        st.push({s[i],m[s[i]]});
                    }
                    else{
                        st.push({s[i],m[s[i]]});
                    }
                }
            }
                   
        }
        
        while(!st.empty()){
            char temp  = st.top().first;
                        st.pop();
                        if(temp!='(')
                        ans += temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends