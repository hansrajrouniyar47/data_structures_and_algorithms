#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int s,int d){
	adj[s].push_back(d);
	adj[d].push_back(s);
}
void printGraph(vector<int> adj[],int V){
	for(int i=0;i<V;i++){
		cout<<i<<": ";
		for(int x:adj[i]){
			cout<<" ,"<<x;
		}
		cout<<endl;
	}
}
void bfs(vector<int> adj[],int s,int V){
     vector<int> visited(V);
     for(int i=0;i<V;i++){
     	visited[i]=false;
     }
     queue<int> q;
     q.push(s);
     visited[s]=true;
     while(!q.empty()){
     	int temp=q.front();
     	cout<<temp<<" ";
     	q.pop();
     	for(int i:adj[temp]){
     		if(!visited[i]){
     			visited[i]=true;
     			q.push(i);
     		}
     	}
     }
     cout<<endl;
}
void dfs(vector<int> adj[],int s,int V){
	vector<int> visited(V);
	stack<int> sk;
	for(int i=0;i<V;i++){
		visited[i]=false;

	}
	sk.push(s);
	visited[s]=true;
	while(!sk.empty()){
		int temp=sk.top();
		cout<<temp<<" ";
		sk.pop();
		for(int x:adj[temp]){
			if(!visited[x]){
				visited[x]=true;
				sk.push(x);
			}
		}
	}
	cout<<endl;
}
int main(){
	int V=5;
	vector<int> adj[V];
    addedge(adj,0,1);
    addedge(adj,0,4);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,2,3);
    addedge(adj,3,4);
    printGraph(adj,V);
    bfs(adj,2,5);
    dfs(adj,2,5);
    return 0;
}
