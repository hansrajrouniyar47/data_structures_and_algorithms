// Rat in a maze problem is a problem based on
// backtracking rather than Graph
// And with simple backtracking on all the possible 
// sides can be solved easily

class Solution{
    public:
    
    void recur(vector<vector<int>> &m,int sr,int sc,int dr,int dc,vector<string> &v,string ans){
        if(sr>=dr || sc>=dc || sr<0 || sc<0 || m[sr][sc]==0 ){
            return;
        }
        if(sr==dr-1 && sc==dc-1){
            v.push_back(ans);
            return;
            
        }
        m[sr][sc]=0;
        recur(m,sr-1,sc,dr,dc,v,ans+"U");
        recur(m,sr+1,sc,dr,dc,v,ans+"D");
        recur(m,sr,sc-1,dr,dc,v,ans+"L");
          recur(m,sr,sc+1,dr,dc,v,ans+"R");
        m[sr][sc]=1;
    
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> v;
        string ans="";
        recur(m,0,0,n,n,v,ans);
        sort(v.begin(),v.end());
        
        return v;
        
    }
};
