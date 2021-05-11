bool isCyclicUtil(int v,vector<bool> &visited,int parent,vector<int> adj[]){
    if(visited[v]==false){
        visited[v]=true;
        
        for(int i:adj[v]){
            if(visited[i]==false){
                if(isCyclicUtil(i,visited,v,adj)){
                    return true;
                }
                
            }
            else if(i==v || i!=parent){
                return true;
            }
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   vector<bool> visited(V);
   for(int i=0;i<V;i++){
       visited[i]=false;
   }
   for(int i=0;i<V;i++){
       if(isCyclicUtil(i,visited,-1,g)){
           return true;
       }
   }
   return false;
}