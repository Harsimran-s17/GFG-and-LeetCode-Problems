//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void solve(vector<int> &vec, stack<int> &s, unordered_set<int> &visited, vector<int> adj[]){
        if(!s.size()){
            return;
        }
        
        int temp = s.top();
        s.pop();
        if(visited.find(temp) == visited.end()){
            visited.insert(temp);
            vec.push_back(temp);
            for(int i = adj[temp].size() - 1; i>=0;i--){
                s.push(adj[temp][i]);
            }
        }
        solve(vec, s, visited, adj);
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        stack<int> s;
        unordered_set<int> visited;
        
        vector<int> vec;
        s.push(0);
        solve(vec, s, visited, adj);
        
        return vec;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends