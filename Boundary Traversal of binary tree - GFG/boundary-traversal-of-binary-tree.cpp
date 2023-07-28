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

    void preOrder(Node * root, vector<int> &leaf){
        if(!root) return;
        if(!root->left &&!root->right) leaf.push_back(root->data);
        preOrder(root->left, leaf);
        preOrder(root->right, leaf);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here 
        queue<Node*> q;
        vector<int> vec;
        vector<int> vec2;
        vector<int> leaf;
        int level = 0;
        bool flag = true;
        
        Node * t = new Node();
        t->data = -1;
        q.push(root);
        q.push(t);
        vec.push_back(root->data);
        if(!root->left && !root->right) return vec;
        
        while(!q.empty()){
            Node * temp = q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
            if(q.front()->data ==-1 ){
                if(temp!=root && root->right && !(!temp->left && !temp->right))
                    vec2.push_back(temp->data);
                q.pop();
                if(q.empty()) break;
                q.push(t);
                if((!q.front()->left && !q.front()->right)) flag = false;
                if(flag && q.front()!=root && root->left)
                vec.push_back(q.front()->data);
            }
        }
        
        preOrder(root, leaf);
        for(auto i : leaf) vec.push_back(i);
        
        reverse(vec2.begin(), vec2.end());
        for(auto i : vec2) vec.push_back(i); 
        
        return vec;
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