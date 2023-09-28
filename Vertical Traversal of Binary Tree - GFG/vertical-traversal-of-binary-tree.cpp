//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void solve(Node* root,long long  int index, unordered_map<int,vector<int>> & m,long long int &lb,long long int &ub){
        if(!root) return ;
        m[index].push_back(root->data);
        lb = min(lb,index);
        ub = max(ub, index);
        solve(root->left, index-1,m,lb,ub);
        solve(root->right, index+1,m,lb,ub);
    }
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        unordered_map<int ,vector<int>> vec;
        int lb = 0;
         int ub = 0;
        vector<int> ans;
        long long int index = 0;
        // solve(root,index,vec, lb,ub);
        queue<pair<int,Node*>> q;
        q.push({0,root});
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;  i< n; i++){
                pair<int,Node *> temp = q.front();
                q.pop();
                vec[temp.first].push_back(temp.second->data);
                lb= min(lb, temp.first);
                ub= max(ub, temp.first);
                if(temp.second->left) q.push({temp.first-1,temp.second->left});
                if(temp.second->right) q.push({temp.first+1, temp.second->right});
            }
        }
        
        for(int i = lb; i <=ub ; i++){
            ans.insert(ans.end(),vec[i].begin(), vec[i].end());
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends