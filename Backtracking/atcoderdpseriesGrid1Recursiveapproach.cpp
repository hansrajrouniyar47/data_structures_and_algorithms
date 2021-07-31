#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long 

ll funcprod(ll num){
	ll mul=1;
	while(num){
		mul*=(num%10);
		num/=10;
	}
}

int main(){
	
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int prod=funcprod(i);
		if(prod<=k){
			count++;
		}
	}
	cout<<count<<endl;

}