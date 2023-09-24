//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void leafNodes(Node * root, vector<int> &vec){
        if(!root->left && !root->right) vec.push_back(root->data);
        if(root->left) leafNodes(root->left, vec);
        if(root->right) leafNodes(root->right, vec);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        vector<int> left;
        vector<int> leaf;
        vector<int> right;
        
        queue<Node *> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node * temp = q.front();
                if(temp->data == -1) {
                    q.pop(); 
                    continue;
                }
                Node * t = new Node();
                t->data = -1;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(!temp->left && !temp->right){
                   q.push(t);
                   continue;
                } 
                else if((i==0 && root->left && !(!temp->left && !temp->right)) || root==temp) left.push_back(temp->data);
                else if(i==n-1 && root->right && !(!temp->left && !temp->right)) right.push_back(temp->data);
            }
        }
        leafNodes(root,leaf);
        // root = root->right;
        // while(root){
        //     if(!(!root->left && !root->right))
        //     right.push_back(root->data);
        //     root = root->right;
        // }
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leaf.begin(), leaf.end());
        reverse(right.begin(), right.end());
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends