//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    
    
    
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    bool ans = true;
	    queue<Node *> lq;
	    queue<Node *> rq;
	    if(root)
	    lq.push(root);
	    if(root)
	    rq.push(root);
	    
	    while(!lq.empty() && !rq.empty()){
	       int n = lq.size();
	       int m = rq.size();
	       if(n!=m) return false;
	       for(int i = 0; i < n; i++){
	           Node * temp = lq.front();
	           lq.pop();
	           Node * temp2 = rq.front();
	           rq.pop();
	           if(temp->right &&  temp2->left){
	               if(temp->right->data !=  temp2->left->data) return false;
	           }
	           else if(temp->left && temp2->right){
	               if(temp->left->data != temp2->right->data) return false;
	           }
	           else if((!temp->left && !temp2->right) || (!temp->right && !temp2->left)){}
	           else return false;
	           
	           if(temp->left) lq.push(temp->left);
	           if(temp->right) lq.push(temp->right);
	           if(temp2->right) rq.push(temp2->right);
	           if(temp2->left) rq.push(temp2->left);
	       }
	       
	    }
	    
	    return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    }
    return 0;
}

// } Driver Code Ends