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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        if(root != NULL){
            max_depth++;
            int left_max = maxDepth(root->left);
            int right_max = maxDepth(root->right);
            max_depth += (left_max > right_max? left_max : right_max);
        }
        return max_depth;
    }
};
