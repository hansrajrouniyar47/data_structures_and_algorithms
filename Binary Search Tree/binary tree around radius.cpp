/**
https://binarysearch.com/problems/Binary-Tree-Nodes-Around-Radius
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 
void recur(Tree* root, vector< vector<int> > &adj){
    if(!root){
        return;
    }
    
    if(root->left){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
    }
    if(root->right){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
    }
    recur(root->left,adj);
    recur(root->right,adj);
}
void findmax(Tree* root,int &maxm){
    if(root==NULL){
        return;
    }
    if(root->val>maxm){
        maxm=root->val;
    }
    findmax(root->left,maxm);
    findmax(root->right,maxm);

}
vector<int> solve(Tree* root, int target, int radius) {
   
    int maxm=0;
    findmax(root,maxm);
    vector< vector<int> > adj(maxm+1);
    
    recur(root,adj);
    
    vector<bool> visited(100001,false);
    vector<int> v;
    queue<int> q;
    queue<int> ql;

    int level=0;
    q.push(target);
    ql.push(level);
    visited[target]=true;
   
    while(!q.empty()){
        int front=q.front();
        int frontlevel=ql.front();
       
        
        q.pop();
        ql.pop();
        if(frontlevel==radius){
            v.push_back(front);
        }
        
        
        for (int i = 0; i<adj[front].size(); ++i){
            if (!visited[adj[front][i]]){
               visited[(adj[front][i])]=true;
               q.push((adj[front][i]));
               ql.push(frontlevel+1);
            }
        }

    }

    sort(v.begin(),v.end());
    return v;
}