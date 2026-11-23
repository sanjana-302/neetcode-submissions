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
    int countMaxNodes = 0;
    void goodNodesHelper(TreeNode* root, TreeNode* max){
        if(!root) return;
        if(root->val>=max->val){
            // cout << root->val << " " << max->val << endl;
            countMaxNodes++;
            max = root;
        }
        goodNodesHelper(root->left,max);
        goodNodesHelper(root->right,max);
        return;
    }
    int goodNodes(TreeNode* root) {
        countMaxNodes++;
        goodNodesHelper(root->left,root);
        goodNodesHelper(root->right,root);
        return countMaxNodes;
    }

    //      3
    //     3 null
    //    4 2
};
