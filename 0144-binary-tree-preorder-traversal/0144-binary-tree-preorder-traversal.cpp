/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode *> s;
        while(root){
            vec.push_back(root->val);
            if(root->right) s.push(root->right);
            if(root->left) root = root->left;
            else if(!s.empty()){
                root = s.top();
                s.pop();
            }
            else root = NULL;
        }
        return vec;
    }
};