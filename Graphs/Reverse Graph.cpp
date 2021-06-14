
// the idea behind reversing a graph is 
// to just add edges from old graph's destination
// to source in the new graph i.e 2d vector

vector<vector<int>> solve(vector<vector<int>>& graph) {
    vector<vector<int>> v(graph.size());
    for(int i=0;i<graph.size();i++){
        for(int x:graph[i]){
            v[x].push_back(i);
        }
    }
    return v;
}