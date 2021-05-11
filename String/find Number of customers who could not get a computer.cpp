
// easy implementation of the questions 
// no trick used 
#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t--){
             int val;
	cin>>val;
	string seq;
	cin>>seq;
	char arr[26];
	memset(arr,0,sizeof(arr));
	int count=0;
	int res=0;
	for(int i=0;i<seq.size();i++){
		if(arr[seq[i]-'A']==0 && (count<val)){
			count++;
			arr[seq[i]-'A']++;
		}
		else if(arr[seq[i]-'A']==0 && (count>=val)){
                                cout<<seq[i];
			res++;
		}
		else if(arr[seq[i]-'A']==1){
			count--;
		}
	}
	cout<<res/2<<endl;
        }

}
