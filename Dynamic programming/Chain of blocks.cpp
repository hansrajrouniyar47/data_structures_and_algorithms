
/*
https://binarysearch.com/problems/Chain-of-Blocks

*/


int solve(vector<vector<int>>& blocks) {
    if(blocks.empty()){
        return 0;
    }
    sort(blocks.begin(),blocks.end());
    int n=blocks.size(),gmax=1;
    unordered_map<int,int> m;
    m.insert({blocks[0][1],1});
    for(int i=1;i<n;i++){
        if(m.find(blocks[i][0])!=m.end()){
            int val=m[blocks[i][0]]+1;
            if(m.find(blocks[i][1])!=m.end()){
                int ans=m[blocks[i][1]];
                ans=(val>ans)?val:ans;
                m[(blocks[i][1])]=ans;
            }
            else{
                m.insert({blocks[i][1],val});
            }
        }
        else{
            m.insert({blocks[i][1],1});
        }
    }
    for(auto i:m){
        if(i.second>gmax){
            gmax=i.second;
        }
    }
    return gmax;
    

}