/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

// the central idea is to do level order traversal
// and take the first element from each level as first 
// element will be the leftmost element and in case
// not present will be right one

vector<int> solve(Tree* root) {
    vector<int> v;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            Tree* cur=q.front();
            q.pop();
            if(i==1){
                v.push_back(cur->val);
            }
            if(cur->left!=NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }
        }
    }
    return v;
}