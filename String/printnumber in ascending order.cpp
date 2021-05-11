// simple idea is to see for numbers if they contain all three 1,2,3 
// if yes then push them in a new vector and later when done 
// sort them and print

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string> vs(n);
	vector<string> newv;
	for(int i=0;i<n;i++){
		cin>>vs[i];
		string smp=vs[i];
		set<char> sc;
		for(int i=0;i<smp.size();i++){
			if(smp[i]=='1' || smp[i]=='2' || smp[i]=='3'){
				sc.insert(smp[i]);
			}
		}
		if(sc.size()==3){
			newv.push_back(smp);
		}
	}
	if(newv.size()==0){
		return -1;
	}
	else{
        sort(newv.begin(),newv.end());
		for(int i=0;i<newv.size();i++){
			cout<<newv[i]<<" ";
		}
	}

}