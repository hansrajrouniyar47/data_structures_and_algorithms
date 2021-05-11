#include<bits/stdc++.h>
using namespace std;
void floodfill(vector<vector<int>> &v,int sr,int sc,string ans,vector<vector<bool>> &visited){
    if(sr<0 || sc<0 || sr==v.size() || sc==v[0].size() || v[sr][sc]==1 || visited[sr][sc]==true){
        return ;
    }
    if(sr==v.size()-1 && sc==v[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    visited[sr][sc]=true;
    floodfill(v,sr-1,sc,ans+"t",visited);
    floodfill(v,sr,sc-1,ans+"l",visited);
    floodfill(v,sr+1,sc,ans+"d",visited);
    floodfill(v,sr,sc+1,ans+"r",visited);
    visited[sr][sc]=false;
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<bool>> visited(r,vector<bool>(c));
    floodfill(v,0,0,"",visited);
}
