


/* the idea is that you traverse the tree in inorder and format 
and insert the elements into the queue and once your finish inserting 
into the queue,
you now pop out the elements and make front element of queue as its
next pointer element
*/

void insertinqueue(struct node* p,queue<node*>& q){
    if(p==NULL){
        return;
    }
    //inserting into the queue in inorder format
    insertinqueue(p->left,q);
    q.push(p);
    insertinqueue(p->right,q);
    
}
void populateNext(struct node* p)
{
 queue<node*> q;
 insertinqueue(p,q);
 //iterating for upto second last element
 // so that it can point its next as last element
 //and last element's next will point to null as usual
 while(q.size()>1){
     node* ans=q.front();
     q.pop();
     ans->next=q.front();
 }
}


/* also this approach can be used 
wherein you are traversing in the preorder and 
a node as prev in which you are storing the prev 
node and making its next as current node


void solve(struct node* p,node* &prev)
{
if(!p){
    return;
}
solve(p->left,prev);
if(prev!=NULL){
    prev->next = p;
    }
    prev=p;
    solve(p->right,prev);
    
}

void populateNext(struct node* p){
    struct node* prev=NULL;
    solve(p,prev);
}

*/