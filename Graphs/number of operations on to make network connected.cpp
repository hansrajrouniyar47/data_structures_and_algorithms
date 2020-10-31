class Solution {
    void dfs(unordered_map<int,vector<int>> &adj,int curr,vector<bool> &visited){
       visited[curr]=true;
        for(int i:adj[curr]){
           if(visited[i]==false){
               dfs(adj,i,visited);
           }
            
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<bool> visited(n,false);
       //step 1: make adjacency list of vectors
        // and count the number of edges
        unordered_map<int,vector<int> >adj;
        int edges=0;
       for(int i=0;i<connections.size();i++){
           adj[connections[i][0]].push_back(connections[i][1]);
           adj[connections[i][1]].push_back(connections[i][0]);
           edges+=1;
       }
        
        //make dfs call so as to know the number of components in graph
        int components=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                components+=1;
                dfs(adj,i,visited);
            }
        }
        //now do calculate for the redundant edge and see if its value is more than or equalto
        // components of graph
        //else return -1
        if(edges<(n-1)){
            return -1;
        }
        int redundant=edges-((n-1)-(components-1));
        if(redundant<(components-1)){
            return -1;
        }
        return components-1;
        
    }
};