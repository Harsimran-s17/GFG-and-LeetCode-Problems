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
        unordered_map<TreeNode*,int> m;
        vector<int> vec;
        while(root){
            if(root->left && m.find(root) == m.end()){
                st.push(root);
                root = root->left;
            }
            else if(root->right){
                if(!m[root])
                vec.push_back(root->val);
                m[root]++;
                root = root->right;
            }
            else {
                if(!m[root])
                vec.push_back(root->val);
                m[root]++;
                if(!st.empty()){
                    root = st.top();
                    st.pop();
                    if(!m[root])
                    vec.push_back(root->val);
                    m[root]++;
                    if(root->right)
                    root = root->right;
                    else if(!st.empty()){
                        root = st.top();
                        st.pop();
                    }
                    else root = NULL;
                }
                else root = NULL;
            }
        }
        return vec;
    }
};