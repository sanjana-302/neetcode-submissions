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
    int result = -1;
    void kthSmallestHelper(TreeNode* root,int& k){
        if(!root) return;
        kthSmallestHelper(root->left,k);
        k--;
        if(k==0) {
            result = root->val;
            return; // prune from here 
        }
        kthSmallestHelper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestHelper(root,k);
        return result;
    }
};
