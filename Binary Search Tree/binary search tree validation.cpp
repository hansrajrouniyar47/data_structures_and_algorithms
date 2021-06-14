/**
https://binarysearch.com/problems/Binary-Search-Tree-Validation
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool check(Tree* root,int minm,int maxm){
    if(root==NULL){
        return true;
    }
    if(root->val<minm || root->val>maxm){
        return false;
    }
    return check(root->left,minm,root->val) && check(root->right,root->val,maxm);
}
bool solve(Tree* root) {
  bool ans=check(root,INT_MIN,INT_MAX);
  return ans;
}