

/*
https://binarysearch.com/problems/Course-Scheduling

*/
bool checkcycle(int s,vector<vector<int>>& courses,vector<bool> &visited,vector<bool> &rstack){
    visited[s]=true;
    rstack[s]=true;
    for(int j=0;j<courses[s].size();j++){
        int i=courses[s][j];
        if(visited[i]==false && checkcycle(i,courses,visited,rstack)==true){
            return true;
        }
        else if(rstack[i]==true){
            return true;
        }
    }
    rstack[s]=false;
    return false;
}

bool solve(vector<vector<int>>& courses) {
    int n=courses.size();
    vector<bool> visited(n,false);
    vector<bool> rstack(n,false);
    for(int i=0;i<n;i++){
      if(visited[i]==false){
          if(checkcycle(i,courses,visited,rstack)){
            
              return false;
          }
      }
    }
    return true;
}