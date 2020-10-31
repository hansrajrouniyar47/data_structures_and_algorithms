

/*
basic idea is you make a new node and make dfs traversal and for each node you 
insert neighbour in them and in case they are visited you simply add them else you add them and 
make recursively dfs call so that in sequence all other nodes too can be visited
*/
class Solution {
public:
    Node* clone_node(Node* node, map<int, Node*> &visited){
        Node* nn=new Node(node->val);
        visited.insert({node->val,nn});
        for(Node* n:node->neighbors){
            auto it=visited.find(n->val);
            if(it==visited.end()){
                // you enter in if condition when you check and see that this node 
                //has not been visited yet 
                //therefore you want to make dfs call so that through this you can call other
                //nodes as well
                Node* cn=clone_node(n,visited);
                nn->neighbors.push_back(cn);
            }
            else{
                //you enter in else condition because this node has been visited
                // and thus you only want to store it as the neighbour of newnode 
                // cause it is the neighbour of original node
                nn->neighbors.push_back(it->second);
            }
        }
        return nn;
        
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        map<int, Node*> visited;
        Node* res=clone_node(node, visited);
        return res;
    }
};