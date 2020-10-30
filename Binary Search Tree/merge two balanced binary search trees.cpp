#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int data){
	Node* temp=new Node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void sortinorder(vector<int> &v,Node* root,int *i){
	if(root==NULL){
		return;
	}
   sortinorder(v,root->left,i);
   v[*i]=root->data;
   *i++;
   sortinorder(v,root->right,i);

}
void mergetwosorted(vector<int> &v1,vector<int> &v2,vector<int> &newv){
	int i=0,j=0,k=0;
	while(i<v1.size() && j<v2.size()){
		if(v1[i]<v2[j]){
			newv[k]=v1[i];
			i++;
		}
		else{
			newv[k]=v2[j];
			j++;
		}
		k++;
	}
	while(i<v1.size()){
		newv[k]=v1[i];
		i++;
		k++;
	}
	while(j<v2.size()){
		newv[k]=v2[j];
		j++;
		k++;
	}

}
Node* constructbst(vector<int> &v,int start,int end){
        if(start>end){
                return NULL;
        }
	int mid=start+(end-start)/2;
	Node* root=newNode(v[mid]);
	root->left=constructbst(v,start,mid-1);
	root->right=constructbst(v,mid+1,end);
	return root;
}
Node* mergetwobst(Node* root1,Node* root2, int n1,int n2){
	vector<int> v1(n1);
	vector<int> v2(n2);
	vector<int> newv(n1+n2);
	int i=0;
	sortinorder(v1,root1,&i);
	int j=0;
	sortinorder(v2,root2,&j);
	mergetwosorted(v1,v2,newv);
	int n=newv.size();
	Node* node=constructbst(newv,0,n-1);
}
void printinorder(Node* node){
	if(node==NULL){
		return;
	}
	printinorder(node->left);
	cout<<node->data<<" ";
	printinorder(node->right);
}
int main(){

        Node *root1 = newNode(100);
        root1->left = newNode(50);
        root1->right = newNode(300);
        root1->left->left = newNode(20);
        root1->left->right = newNode(70);

        Node *root2 = newNode(80);
        root2->left     = newNode(40);
        root2->right = newNode(120);

        int n1=5;
        int n2=3;

	Node* node=mergetwobst(root1,root2,n1,n2);
	printinorder(node);
	return 0;
}
