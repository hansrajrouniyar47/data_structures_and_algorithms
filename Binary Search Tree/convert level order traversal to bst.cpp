/*the idea here is that first you do create a root with first
node and then for other remaining nodes do traverse
and see where they fit in and do create a new node there
and we do this for evert element in the array 
ie create node for every element and store them in their
respective place



*/


Node* LevelOrder(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data<=root->data){
        root->left=LevelOrder(root->left,data);
    }
    else{
        root->right=LevelOrder(root->right,data);
    }
    return root;
}
Node* constructBst(int arr[], int n)
{
    
  Node* root=NULL;
  for(int i=0;i<n;i++){
      root=LevelOrder(root,arr[i]);
  }
  return root;
	
}
