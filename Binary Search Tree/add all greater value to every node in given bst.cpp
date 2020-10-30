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
/* the basic idea is do reverse inorder traversal in which i go to the rightmost
subtree's right most node and since this is the biggest value in bst therefore here i
need not add any value but then since i move to its parent they have value smaller than 
their right child and thus i can add their right child
*/

class Solution {
public:
    TreeNode* modifiedbst(TreeNode* root, int &sum){
        if(root==nullptr){
            return nullptr;
        }
        modifiedbst(root->right,sum);
        
        root->val+=sum;
        sum=root->val;
        modifiedbst(root->left,sum);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        TreeNode* node=modifiedbst(root,sum);
        return node;
    }
};