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
    bool isBalanced(TreeNode* root) { 
        if(getHeight(root) != -1) return true;
        else return false;
    }

    int getHeight(TreeNode* cur){ // return -1 if imbalanced
        if(cur == nullptr) return 0;

        int left_h = getHeight(cur->left);
        int right_h = getHeight(cur->right);

        if (left_h == -1 || right_h == -1 || abs(left_h - right_h) > 1) return -1;
        else return (1 + max(left_h, right_h));
    }
};
