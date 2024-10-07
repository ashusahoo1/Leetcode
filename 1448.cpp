//1448


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
    // Helper function to traverse the tree and count good nodes
    int traverse(TreeNode* root, int val) {
        if (root == NULL) return 0;  // Base case: no node
        int temp = 0;
        if (root->val >= val) {
            temp = 1;  // Current node is good
        } 
        val = max(val, root->val);  // Update maximum value encountered
        // Recursively count good nodes in left and right subtrees
        return temp + traverse(root->right, val) + traverse(root->left, val);
    }

    // Main function to count good nodes
    int goodNodes(TreeNode* root) {
        return traverse(root, INT_MIN);  // Start traversal with minimum integer
    }
};
