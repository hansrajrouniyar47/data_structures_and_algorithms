
/*
https://binarysearch.com/problems/Maximum-Unique-Sublist-Sum

*/



int solve(vector<int>& nums) {
    int n=nums.size();
    set<int> s;
    s.insert(nums[0]);
    int maxm=nums[0],sum=nums[0],i=0,j=1;
    while(i<n-1 && j<n){
        if(s.count(nums[j])>0){
            sum-=nums[i];
            s.erase(nums[i]);
            i++;
        }
        else{
            sum+=nums[j];
            s.insert(nums[j]);
            maxm=max(maxm,sum);
            j++;
        }
    }

    return maxm;
}