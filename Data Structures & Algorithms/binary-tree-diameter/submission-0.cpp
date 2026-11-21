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
    // diameter of tree : node + height(left) + height(right)
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }

    int findDiameterOfNode(TreeNode* root){
        if(!root) return 0;
        return depth(root->left) + depth(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return max(findDiameterOfNode(root),max(findDiameterOfNode(root->left),findDiameterOfNode(root->right)));
    }
};
