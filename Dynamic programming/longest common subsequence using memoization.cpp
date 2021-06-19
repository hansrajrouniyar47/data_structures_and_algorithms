
/*
https://binarysearch.com/problems/Longest-Common-Subsequence

Using memoization

*/

int lcs(string a,string b,int m,int n,vector<vector<int>> &dp){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m-1][n-1]!=-1){
        return dp[m-1][n-1];
    }
    if(a[m-1]==b[n-1]){
        dp[m-1][n-1] =1+lcs(a,b,m-1,n-1,dp);
    }
    else{
        dp[m-1][n-1]=max(lcs(a,b,m,n-1,dp),lcs(a,b,m-1,n,dp));
    }
    return dp[m-1][n-1];
}
int solve(string a, string b) {
    int m=a.size(),n=b.size();
    int maxm=1000;
    vector<vector<int>> dp(maxm,vector<int>(maxm,-1));
    int ans=lcs(a,b,m,n,dp);
    return ans;
}