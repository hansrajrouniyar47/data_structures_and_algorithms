#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int gsum=INT_MAX;
void recursionsolve(vector<int> &v,int i,int n,int lsum,int vsum){
    if(i==n){
        int sum=vsum-lsum;
        //cout<<sum<<endl;
        if(sum<gsum && sum!=0){
            gsum=sum;
            cout<<gsum<<endl;
        }
        return;
    }
    recursionsolve(v,i+1,n,lsum+v[i],vsum);
    recursionsolve(v,i+1,n,lsum,vsum);
    
}
int main()
{
	int n;
    cin>>n;
    vector<int> v(n);
    int vsum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        vsum+=v[i];
       
    }
    recursionsolve(v,0,n,0,vsum);
    cout<<gsum<<endl;
	return 0;
}