
/*The idea is simple that is in each step
 do subtract the node’s value with the given
  sum value and check if reaching at leaf 
  node it is equal to 0, if it is means yes 
  the sum is one of the sum of binary tree else not,

*/

bool hasPathSum(Node *node, int sum) {
    if(node==NULL){
        return (sum==0);
    }
    int subsum=sum-node->data;
    if(subsum==0 && node->left==NULL && node->right==NULL){
        return 1;
    }
    int ans=0;
    if(node->left){
        ans=ans||hasPathSum(node->left,subsum);
        
    }
    if(node->right){
        ans=ans||hasPathSum(node->right,subsum);
    }
    return ans;
}