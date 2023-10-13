//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node * solve(int in[], int pre[], int i, int n, int s){
        if(i>=n) return NULL;
        Node * root = new Node(pre[s]);
        int r = pre[s];
        int j = i;
        int l = s+1;
        while(in[j]!=r){
            j++;
            s++;
        }
        root->left = solve(in,pre,i,j,l);
        root->right = solve(in,pre,j+1,n,s+1);
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return solve(in,pre,0,n,0);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends