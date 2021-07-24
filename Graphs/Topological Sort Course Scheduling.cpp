/*
link to problem: https://leetcode.com/problems/course-schedule/

Also if we want to return the vertex topologically sorted,
we could do that as inside topological sortfunction we could 
have declared an array topo and insert every dequed element
in the hieararchy getting the ordered elements in 
topological sort as -- operation would help in the ordering
*/

class Solution {
public:
    bool topologicalsort(int n,vector<vector<int>> &adj){
        queue<int> q;
        vector<int> indegree(n,0),visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            for(auto child:adj[i]){
                indegree[child]+=1;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i]=true;
            }
        }
        while(!q.empty()){
            int vertex=q.front();
            q.pop();
            for(int i:adj[vertex]){
                if(visited[i]==false){
                    indegree[i]--;
                    if(indegree[i]==0){
                        q.push(i);
                        visited[i]=true;
                    }
                }
            }
            count++;
            
        }
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       for(int i=0;i<prerequisites.size();i++){
           adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
       }
       bool ans=topologicalsort(numCourses,adj);
        return ans;
    }
};