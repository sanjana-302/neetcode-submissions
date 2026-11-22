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
    bool result = true;
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void isBalancedHelper(TreeNode* root){
        if(!root) return;
        int findLeftHt = height(root->left);
        int findRightHt = height(root->right);

        if(abs(findLeftHt-findRightHt)>1) result = false;
        isBalancedHelper(root->left);
        isBalancedHelper(root->right);
    }
    bool isBalanced(TreeNode* root) {
        isBalancedHelper(root);
        return result;
    }
};
