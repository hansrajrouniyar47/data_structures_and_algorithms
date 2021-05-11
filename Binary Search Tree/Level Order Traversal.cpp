/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

// The idea is to use a queue and do the BFS traversal
// over the bst 


vector<int> solve(Tree* root) {
    queue<Tree* > q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        Tree* temp=q.front();
        v.push_back(temp->val);
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return v;
}