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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()){
            int size = q.size();

            // push all nodes out of queue, except last 
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                // for last element in this level append to array 
                if(size==0) res.push_back(front->val);
            }
        }

        return res;
    }
};
