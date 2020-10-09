#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    vector<vector<int>> v1(n+1),v2(n+1);
	    for(int i=0;i<e;i++){
	        int u,v;
	        cin>>u>>v;
	        if(u>v){
	            swap(u,v);
	        }
	        v1[u].push_back(v);
	    }
	    for(int i=0;i<e;i++){
	        int u,v;
	        cin>>u>>v;
	        if(u>v){
	            swap(u,v);
	        }
	        v2[u].push_back(v);
	    }
	    queue<int> q;
	    vector<int> res1,res2;
	    q.push(1);
	    while(!q.empty()){
	        int a=q.front();
	        q.pop();
	        res1.push_back(a);
	        for(int i:v1[a]){
	            q.push(i);
	        }
	    }
	    q.push(1);
	    while(!q.empty()){
	        int a=q.front();
	        q.pop();
	        res2.push_back(a);
	        for(int i=v2[a].size()-1;i>=0;i--){
	            q.push(v2[a][i]);
	        }
	    }
	    bool ans=res1.size()==res2.size();
	   for(int i=0;i<res1.size();i++){
	       if(res1[i]!=res2[i]){
	           ans=false;
	           break;
	       }
	   }
	   cout<<ans<<endl;
	    
	    
	}
	return 0;
}
