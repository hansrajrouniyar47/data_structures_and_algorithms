/**
https://binarysearch.com/problems/Next-Node-on-Its-Right
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* nextRight(Tree *root, int k)
{
    if(!root){
        return NULL;
    }

    queue<Tree* >qroot;
    queue<int >qlevel;
    int level=0;
    qroot.push(root);
    qlevel.push(level);

    while(!qroot.empty()){
        Tree* qfrontnode=qroot.front();
        int qlevelval=qlevel.front();
        qroot.pop();
        qlevel.pop();
        if(qfrontnode->val==k){
            if(qroot.empty() || qlevelval!=qlevel.front()){
                return NULL;
            }
            return qroot.front();
        }
        if(qfrontnode->left!=NULL){
            qroot.push(qfrontnode->left);
            qlevel.push(qlevelval+1);
        }
        if(qfrontnode->right!=NULL){
            qroot.push(qfrontnode->right);
            qlevel.push(qlevelval+1);
        }
    }


    return NULL;
}
Tree* solve(Tree* tree, int target) {


    Tree* ans=nextRight(tree,target);
    return ans;
}