
/* the idea is really simple which is traverse and 
store the node in inorder fashion in the vector and then
sort it 
and finally when the data in sorted now it can easily be
translated to bst*/

void storeinorder(Node* root,vector<int> &v){
	if(root==NULL){
		return;
	}
	storeinorder(root->left,v);
	v.push_back(root->data);
	storeinorder(root->right,v);
}
void arraytobst(vector<int> &v,Node* root,int &i){
	if(root==NULL || i>v.size()){
		return;
	}
	arraytobst(v,root->left,i);
	root->data=v[i];
	i++;
	arraytobst(v,root->right,i);
	

}


Node *binaryTreeToBST (Node *root)
{
    if(root==NULL){
    	return NULL;
    }
    vector<int> v;
    
    storeinorder(root,v);
    sort(v.begin(),v.end());
    int i=0;
    arraytobst(v,root,i);
    return root;
}