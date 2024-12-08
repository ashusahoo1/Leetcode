//230. Kth Smallest Element in a BST

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0; // Counter to track the current element during traversal
        return inorder(root, i, k);
    }

private:
    int inorder(TreeNode* root, int& i, int k) {
        if (root == nullptr) {
            return -1; // Base case: return -1 if no node exists
        }
        
        // Traverse the left subtree
        int left = inorder(root->left, i, k);
        if (left != -1) {
            return left; // If the result is found in the left subtree, return it
        }
        
        // Increment the counter for the current node
        i++;
        if (i == k) {
            return root->val; // Return the k-th smallest value
        }
        
        // Traverse the right subtree
        return inorder(root->right, i, k);
    }
};
