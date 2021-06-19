
/*
https://binarysearch.com/problems/Hoppable
*/

bool solve(vector<int>& nums) {
    if(nums.size()<2){
        return true;
    }
    int n=nums.size(),val,temp;
    vector<int> dp(n,0);
    for(int i=n-2;i>0;i--){
        val=dp[i+1]-1;
        val=(val<0)?(-1*val):val;
        temp=nums[i]-(val);
        if(temp>=0){
            dp[i]=0;
        }
        else{
            dp[i]=(-1*val);
        }
       
    }
    val=dp[1]-1;
    val=(val<0)?(-1*val):val;
    temp=nums[0]-(val);
    if(temp>=0){
        return true;
    }
    return false;
}