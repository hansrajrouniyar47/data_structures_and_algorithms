/*

https://binarysearch.com/problems/Shortest-Path-in-a-Graph
*/

int solve(vector<vector<int>>& edges, int start, int end) {
        int n=0;
        for(int i=0;i<edges.size();i++){
            n=max(n,max(edges[i][0],edges[i][1]));
        }
        vector<vector<pair<int,int>>> adj(n+1);
        
      
        vector<int> dist(n+1,100000);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        using pi=pair<int,int>;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
       
        dist[start]=0;
        
        pq.push({0,start});        
        while(!pq.empty())
        {
           
            auto [time,top]=pq.top();
            pq.pop();
            
          
            for(auto[node,t] : adj[top])
            {
                if(dist[node]> time + t)
                {
                  
                    dist[node]=time+t;
                    pq.push({dist[node],node});
                }
            }
        }
        if(dist[end]==100000){
            return -1;
        }
        return dist[end];


}