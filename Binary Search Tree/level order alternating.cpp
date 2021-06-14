/**
https://binarysearch.com/problems/Level-Order-Alternating
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    deque<Tree* > q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->val);
    Tree* temp;
   
    // set initial level as 1, because root is
    // already been taken care of.
    int l = 1;
                
    while (!q.empty()) {
        int n = q.size();
 
        for (int i = 0; i < n; i++) {
 
            // popping mechanism
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }
 
            // pushing mechanism
            if (l % 2 != 0) {
 
                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->val);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->val);
                }
            }
            else if (l % 2 == 0) {
 
                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->val);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->val);
                }
            }
        }
        l++; // level plus one
    }
    return v;
}