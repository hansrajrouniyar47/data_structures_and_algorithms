
the idea is simple just as we compute from string to int value for excel 
sheet in the way as pow(26,i)+(ch-'A')+1
here we reverse the process and divide by 26 and find the rem which if 26 
will be equal to Z else 
we will match to the corresponding characters


string ExcelColumn(int N)
{
    int i=0;
    char str[50];
    while(N>0){
        int rem=N%26;
        if(rem==0){
            str[i++]='Z';
            N=N/26-1;
        }
        else{
            str[i++]=(rem-1)+'A';
            N/=26;
        }
    }
    str[i]='\0';
    reverse(str,str+strlen(str));
    return str;
}