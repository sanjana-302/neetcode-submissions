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
        if(p->val<root->val && q->val<root->val){
            result = lowestCommonAncestor(root->left,p,q);
        }else if(p->val>root->val && q->val>root->val){
            result = lowestCommonAncestor(root->right,p,q);
        }else if(p->val>root->val && q->val<root->val || p->val<root->val && q->val>root->val){
            return root;
        }else{
            if(p->val==root->val){
                return p;
            }else{
                return q;
            }
        }

        return result;

    }
};
