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
    int maxSum = INT_MIN;
    int maxPathSumHelper(TreeNode* root){
        if(!root) return 0;
        // if(!root->left && !root->right) return root->val;
        int leftMaxSum = max(0,maxPathSumHelper(root->left));
        int rightMaxSum = max(0,maxPathSumHelper(root->right));

        maxSum = max(maxSum,root->val + leftMaxSum + rightMaxSum);

        return root->val + max(leftMaxSum, rightMaxSum);;

    }
    int maxPathSum(TreeNode* root) {
        // at a node
        // max path sum can be 
        // root->val + left + right or root->val + left or root->val + right or just left or just right 
        maxPathSumHelper(root);
        return maxSum;
    }
};
