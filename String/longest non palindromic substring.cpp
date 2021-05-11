#include<bits/stdc++.h> 
using namespace std;
bool ispalindrome(string s){
	int j=s.size()-1;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[j]){
			return false;
		}
		j--;
	}
	return true;
}
int findlengthpalindrome(string s){
	char ch=s[0];
	int n=s.size();
	int i=1;
	for(;i<n;i++){
		if(s[i]!=ch){
			break;

		}
	}
	if(i==n){
		return 0;
	}
	if(ispalindrome(s)){
		return n-1;
	}
	return n;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int res=findlengthpalindrome(s);
		cout<<res<<endl;
	}
}