#include<bits/stdc++.h>
using namespace std;
 
int main(){
	
		int n,k;
		cin>>n>>k;
		int jumps[n];
		for(int i=0;i<n;i++){
			cin>>jumps[i];
		}
        int val=INT_MAX;
		vector<int> dp(n,val);
        dp[0]=0;
		for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+k;j++){
                if(j<n){
                    dp[j]=min(dp[j],dp[i]+abs(jumps[i]-jumps[j]));
                }
            }
        }
        cout<<dp[n-1]<<endl;
		return 0;
 
        
	
}