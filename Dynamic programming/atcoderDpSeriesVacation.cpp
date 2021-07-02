#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	int n;
	cin>>n;
	int val[n][3];
	for(int i=0;i<n;i++){
		cin>>val[i][0]>>val[i][1]>>val[i][2];
	}
	int dp[n][3];
	dp[0][0]=val[0][0];
	dp[0][1]=val[0][1];
	dp[0][2]=val[0][2];
	for(int i=1;i<n;i++){
		dp[i][0]=val[i][0]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=val[i][1]+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=val[i][2]+max(dp[i-1][0],dp[i-1][1]);
        //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	int fval=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	cout<<fval<<endl;
        
	
}