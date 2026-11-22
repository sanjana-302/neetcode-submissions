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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> result;

        if(root) q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> sublist;
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                sublist.push_back(front->val);
            }
            result.push_back(sublist);
        }

        return result;
        
    }
};
