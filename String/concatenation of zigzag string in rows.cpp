#include <iostream>
using namespace std;
 // so the idea here is that you make n different arrays and 
 // append in them row wise 
 // just to keep in mind that you maintain the order of row
 // by row to down and again while returning you return from down 
 // only 
 // which can be done by keeping a boolean variable down 
 // and incrementing and decrementing the row accordingly
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        int n;
        cin>>s;
        cin>>n;
        string arr[n];
        int row=0;
        bool down=false;
        if(n==1){
            cout<<s<<endl;
            continue;
        }
        for(int i=0;i<s.size();i++){
            arr[row].push_back(s[i]);
            if(row==0){
                down=true;
            }
            else if(row==n-1){
                down=false;
            }
            down?row++:row--;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
        
    }
	return 0;
}