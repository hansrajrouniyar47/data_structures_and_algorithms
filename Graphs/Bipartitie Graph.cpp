
// to solve bipartite graph we have to 
// believe on notion that no vertex acts on
// both the sides of graph and thus we color the vertex
// differently by BFS travel as if a node is colored 
// in one color all its neighbours in other color
// and again all its neighbours back in first color
// and in that process if any of the vertex is having
// same color as from its origin neighbours
// we return false saying the graph is not bipartite


bool solve(vector<vector<int>>& graph) {
   
     vector<int> color(graph.size(),-1);
   queue<int> q;

    for(int i=0;i<graph.size();i++){
        if(color[i]!=-1){
            continue;
        }
        q.push(i);
        color[i]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int x:graph[curr]){
                if(color[x]==-1){
                    color[x]=1-color[curr];
                    q.push(x);
                }
                else if(color[x]==color[curr]){
                    return false;
                }
            }
        }
    }
    return true;
}