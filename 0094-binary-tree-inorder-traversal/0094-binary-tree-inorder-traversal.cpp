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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        while(true){
            if(root){
                st.push(root);
                root = root->left;
            }
            else if(st.empty()) break;
            else{
                vec.push_back(st.top()->val);
                if(st.top()->right){
                    root = st.top()->right;
                }
                st.pop();
            }
        }
        return vec;
    }
};