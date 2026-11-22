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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode* result = nullptr;
        if(p->val<root->val && q->val<root->val){ // both in left subtree
            result = lowestCommonAncestor(root->left,p,q);
        }else if(p->val>root->val && q->val>root->val){ // both in right subtree
            result = lowestCommonAncestor(root->right,p,q);
        }else if(p->val>root->val && q->val<root->val || p->val<root->val && q->val>root->val){
            // both on opposite subtree
            return root;
        }else{
            // root equates to one of the values
            if(p->val==root->val){
                return p;
            }else{
                return q;
            }
        }

        return result;

    }
};
