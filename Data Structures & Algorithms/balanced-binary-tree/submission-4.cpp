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
    bool isBalanced(TreeNode* root) { // O(n^2) worst case
        if(root == nullptr) return true;
        if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
        int left_h = getHeight(root->left); // O(n)
        int right_h = getHeight(root->right);

        if(abs(left_h - right_h) > 1) return false;
        return true;
    }

    int getHeight(TreeNode* cur){ // O(n)
        if(cur == nullptr) return 0;

        int left_h = getHeight(cur->left);
        int right_h = getHeight(cur->right);

        return 1 + max(left_h, right_h);
    }
};
