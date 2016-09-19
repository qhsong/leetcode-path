/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return checkSymmetic(root->left, root->right);    
    }
    
    bool checkSymmetic(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right== NULL) return false;
        if(left->val == right->val) {
            return checkSymmetic(left->right, right->left) && checkSymmetic(left->left, right->right);
        }
        return false;
        
    }
};