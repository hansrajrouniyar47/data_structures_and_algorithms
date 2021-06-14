/**
https://binarysearch.com/problems/Height-Balanced-Tree
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int maxheight(Tree* root,bool &flag){
    if(root==NULL){
        return 0;
    }
    int lefth=maxheight(root->left,flag);
    int righth=maxheight(root->right,flag);
    if(abs(lefth-righth)>1){
        flag=flag&&false;
     
    }
    else{
        flag=flag&&true;
        
    }
    
    int ans=(lefth>righth)?lefth:righth;
    
    return ans+1;
    

}
bool solve(Tree* root) {
    bool flag=true;
    maxheight(root,flag);
    return flag;
}