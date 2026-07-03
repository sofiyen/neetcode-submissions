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
    int globalDia = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ret = maxPath(root);
        
        return globalDia;
    }

    int maxPath(TreeNode* cur){
        if(!cur) return 0;
        
        int leftMax = 0;
        int rightMax = 0;
        int curDia = 0;

        if(cur->left) leftMax = (maxPath(cur->left) + 1);
        if(cur->right) rightMax = (maxPath(cur->right) + 1);

        curDia = leftMax + rightMax;
        globalDia = (curDia > globalDia? curDia: globalDia);
        
        return (leftMax > rightMax? leftMax: rightMax);
    }
};
