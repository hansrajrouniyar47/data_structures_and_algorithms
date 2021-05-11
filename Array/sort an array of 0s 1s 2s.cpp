 // coode here 
    /*
    int co=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            co++;
        }
        else if(a[i]==1){
            c1++;
        }
        else if(a[i]==2){
            c2++;
        }
    }
   for(int i=0;i<n;i++){
       if(co>0){
           a[i]=0;
           co--;
       }
       else if(c1>0){
           a[i]=1;
           c1--;
       }
       else if(c2>0){
           a[i]=2;
           c2--;
       }
   }
   */
  //both algorithm works but the latter one 
 //which is dutch national flag algorithm can work
 //for negative case as well 
int low=0,mid=0,high=n-1;
while(mid<=high){
	if(a[mid]==0){
		swap(a[mid],a[low]);
		low++;
		mid++;
	}
	else if(a[mid]==1){
		mid++;
	}
	else if(a[mid]==2){
		swap(a[high],a[mid]);
		high--;
		mid;
	}

}