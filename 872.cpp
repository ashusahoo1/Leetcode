//872. Leaf-Similar Trees


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
vector<int>v;
vector<int>v1;
    void inorder(TreeNode* root,vector<int>&result)
    {
        if(root==NULL)
        return;
        inorder(root->left,result);
        if(root->left==NULL && root->right==NULL)
        {
           result.push_back(root->val);
        }
        inorder(root->right,result);
    }
 
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      inorder(root1,v);
      inorder(root2,v1);
      if(v1.size()!=v.size())
      return 0;
      return v==v1;
      
    }
};
