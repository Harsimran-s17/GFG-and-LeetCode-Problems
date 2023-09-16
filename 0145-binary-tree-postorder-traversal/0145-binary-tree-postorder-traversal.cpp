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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> s1;
        vector<int> vec;
        
        while(root){
           if(root->left){
               s1.push({root,0});
               root = root->left;
           }
           else if(root->right){
               s1.push({root,1});
               root = root->right;
           }
           else{
               vec.push_back(root->val);
               while(!s1.empty()){
                   if(s1.top().second == 0 && s1.top().first->right){
                       root = s1.top().first->right;
                       s1.top().second = 1;
                       break;
                   }
                   else{
                       vec.push_back(s1.top().first->val);
                       s1.pop();
                   }
               }
               if(s1.empty()){
                   root = NULL;
                   break;
               }
           }
        }
        return vec;
    }
};