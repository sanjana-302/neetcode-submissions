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
    vector<int> inorderValues;
    void inorderTraversal(TreeNode* root){
        if(!root) return;
        inorderTraversal(root->left);
        inorderValues.push_back(root->val);
        inorderTraversal(root->right);
    }
    bool traverseWithRanges(TreeNode* root,int leftBoundary,int rightBoundary){
        if(!root) return true;
        if(root->val <= leftBoundary || root->val >= rightBoundary) return false;

        bool isLeftSubtreeBST = traverseWithRanges(root->left,leftBoundary,root->val);
        bool isRightSubtreeBST = traverseWithRanges(root->right,root->val,rightBoundary);

        return (root->val > leftBoundary && root->val < rightBoundary) && isLeftSubtreeBST && isRightSubtreeBST;
    }
    bool isValidBST(TreeNode* root) {
        // inorderTraversal(root); Tc : O(n), Sc : O(n) + O(h)
        return traverseWithRanges(root,INT_MIN,INT_MAX);
    }
};
