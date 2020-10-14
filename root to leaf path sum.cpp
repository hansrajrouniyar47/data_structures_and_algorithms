
/*The idea is simple that is in each step
 do subtract the node’s value with the given
  sum value and check if reaching at leaf 
  node it is equal to 0, if it is means yes 
  the sum is one of the sum of binary tree else not,

*/

bool hasPathSum(Node *node, int sum) {
    // if you reach at a null node that means you are beyond 
    //leaf node and thus check if sum has been 0 and return accordingly
    if(node==NULL){
        return (sum==0);
    }
    int subsum=sum-node->data;
    //if you have reached leaf node and your sum is 0 after deducting 
    //corresponding value at simultaneously at travelled node
    if(subsum==0 && node->left==NULL && node->right==NULL){
        return 1;
    }
    int ans=0;
    if(node->left){
        // you are taking or value that is anytime you would have got 1 then 
        //always the value would be 1
        ans=ans||hasPathSum(node->left,subsum);
        
    }
    //same on right hand side
    if(node->right){
        ans=ans||hasPathSum(node->right,subsum);
    }
    return ans;
}