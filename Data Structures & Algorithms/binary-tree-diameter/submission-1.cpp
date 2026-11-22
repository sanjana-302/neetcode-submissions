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
    // n^2 solution 
    int maxDiameter = INT_MIN;
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }

    void findDiameterOfNode(TreeNode* root){
        if(!root) return;
        int leftHeight = depth(root->left);
        int rightHeight = depth(root->right);

        if(leftHeight+rightHeight>maxDiameter) maxDiameter = leftHeight+rightHeight;

        findDiameterOfNode(root->left);
        findDiameterOfNode(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        findDiameterOfNode(root);
        return maxDiameter;
    }
};
