
/*
https://binarysearch.com/problems/Longest-Increasing-Subsequence


*/


int solve(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int n=nums.size();
    vector<int> v(n);
    v[0]=1;
    
    int gmax=1;
    for(int i=1;i<n;i++){
        int maxm=0;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                maxm=max(maxm,v[j]);
                
            }
        }
       
        v[i]=maxm+1;
        gmax=max(gmax,v[i]);
    }
    return gmax;

}