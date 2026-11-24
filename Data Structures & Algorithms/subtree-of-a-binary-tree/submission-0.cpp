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
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false; 

        return root->val==subRoot->val && isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false; 

        if(root->val==subRoot->val){
            // call helper is identical function 
            bool possibleMatch = isIdentical(root,subRoot);
            if(possibleMatch) return possibleMatch;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
