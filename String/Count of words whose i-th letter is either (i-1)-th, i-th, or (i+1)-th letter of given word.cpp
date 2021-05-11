#include<bits/stdc++.h>
using namespace std;
int calcount(char carr[],int n){
	int c=1;
	if(n==1){
		return c;
	}
	// see for the starting letter as it can have only 1 or 2 probability
	if(carr[0]==carr[1]){
		c*=1;
	}
	else{
		c*=2;
	}
	// see for middle as it can have 1,2 and 3 possibilities
	for(int i=1;i<n-1;i++){
		if(carr[i-1]==carr[i]==carr[i+1]){
			c*=1;
		}
		else if(carr[i]==carr[i-1] || carr[i]==carr[i+1] || carr[i-1]==carr[i+1]){
			c*=2;
		}
		else{
			c*=3;
		}
	}
	// see for the last char as it can have 1 or 2 probabilities
	if(carr[n-2]==carr[n-1]){
		c*=1;
	}
	else{
		c*=2;
	}
	return c;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		char carr[n+1];
		strcpy(carr,s.c_str());
		int numvalue=calcount(carr,n);
		cout<<numvalue<<endl;

	}
	return 0;
}