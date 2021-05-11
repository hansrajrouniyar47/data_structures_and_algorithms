// the recursive solution is below wherein the approach is that 
// first i need to take my first element into consideration and raise two conditions 
// which is 1/ i will move on with taking this into consideration 
// 2/ the other that i won't take this into consideration and move ahead for other possible subsequences
// now the thing is that this element which i had taken into consideration that will be prev for the current
// element and i check the condition that is if my element at current index is greater than what i had taken
// if so i add it and again call for further arrays
//         and here as well i will taken another condition of not taking this element into consideration,
// now the thing is that: in such i will return to the end and start returning bothwise and return max 

#include<bits/stdc++.h>
using namespace std;
int fans(int arr[],int prev,int index,int findex){
        if(index==findex){
                return 0;
        }
        int include=0;
        if(arr[index]>prev){
                include=arr[index]+fans(arr,arr[index],index+1,findex);
        }
        int notinclude=fans(arr,prev,index+1,findex);
        return max(include,notinclude);
}
int main(){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
                cin>>arr[i];
        }
        int findex=n;
        int fanswer=fans(arr,0,0,findex);
        cout<<fanswer;
        return 0;
}
// dp solution
class Solution{
                

        public:
        int maxSumIS(int arr[], int n)  
        {  
            // Your code goes here
            int na[n];
            for(int i=0;i<n;i++){
                na[i]=arr[i];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(arr[j]<arr[i]){
                        na[i]=max(na[i],arr[i]+na[j]);
                    }
                }
            }
            int maxm=0;
            for(int i=0;i<n;i++){
                if(na[i]>maxm){
                    maxm=na[i];
                }
            }
            return maxm;
        }  
};