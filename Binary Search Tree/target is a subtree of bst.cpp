/**
https://binarysearch.com/problems/Subtree
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool checkboth(Tree* root,Tree* target){
    if(root==NULL && target==NULL){
        return true;
    }
    if((root==NULL && target!=NULL)||(root!=NULL && target==NULL)){
        return false;
    }
    if(root->val!=target->val){
        return false;
    }
    bool ans1=checkboth(root->left,target->left);
    bool ans2=checkboth(root->right,target->right);
    return ans1&&ans2;
}
void checkinitials(Tree* root,Tree* target,bool &flag){
  if(root==NULL){
      return;
  }
  if(root->val==target->val){
      flag=checkboth(root,target);
      return;
  }
  if(root->val<target->val){
      checkinitials(root->right,target,flag);
  }
  if(root->val>target->val){
      checkinitials(root->left,target,flag);
  }
}
bool solve(Tree* root, Tree* target) {
    bool flag=false;
    checkinitials(root,target,flag);
    return flag;
}