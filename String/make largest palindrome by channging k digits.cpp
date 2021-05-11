#include<bits/stdc++.h>
using namespace std;
void makepalindrome(string s,int k){
	int l=0;
	int r=s.size()-1;
	string palindrome=s;
	while(l<r){
		if(palindrome[l]!=palindrome[r]){
			palindrome[l]=palindrome[r]=max(palindrome[l],palindrome[r]);
			k--;
		}
		l++;
		r--;

	}
	if(k<0){
		cout<<"-1"<<endl;
		return;
	}
	l=0;
	r=s.size()-1;
	while(l<=r){
		if(l==r){
			if(k>0){
				palindrome[l]=palindrome[r]='9';
				k--;
			}
		}
		if(palindrome[l]<'9'){
			if(k>=2 && palindrome[l]==s[l] && palindrome[r]==s[r]){
				palindrome[l]=palindrome[r]='9';
				k-=2;
			}
			if(k>=1 && (palindrome[l]!=s[l] || palindrome[r]!=s[r])){
					palindrome[l]=palindrome[r]='9';
			}
		}
		l++;
		r--;
	}
	cout<<palindrome<<endl;
}
int main(){
	int t; 
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int k;
		cin>>k;
		makepalindrome(s,k);

	}
	return 0;
}