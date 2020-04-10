// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        auto* left = lowestCommonAncestor(root->left, p, q);
        auto* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        if(!left) return right;
        return left;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);    
        }
        else if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);    
        }
        return root;
    }
};
