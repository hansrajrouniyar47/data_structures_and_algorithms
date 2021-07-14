/*

https://binarysearch.com/problems/Dice-Throw

*/



int mod = (int)1e9 + 7;
int recursiveways(int n,int faces,int total,vector<vector<int>> &dp){
    if(total==0 && n==0){
        return 1;
    }
    if(total<0 || n==0){
        return 0;
    }
    if(dp[n][total]!=-1){
        return dp[n][total];
    }
    int ans=0;
    for(int i=1;i<=faces;i++){
        ans+=recursiveways(n-1,faces,total-i,dp)%mod;
        ans%=mod;
    }
    ans%=mod;
    dp[n][total]=ans;
    return dp[n][total];
}
int solve(int n, int faces, int total) {
   vector<vector<int>> dp(101,vector<int>(101,-1));
    int ftotal=recursiveways(n,faces,total,dp);
    return ftotal;
}