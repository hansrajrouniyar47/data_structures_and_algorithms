/*
https://binarysearch.com/problems/Number-of-Sublists-With-Sum-of-Target

*/



int solve(vector<int>& nums, int target) {
   int n = nums.size(), c = 0, sum = 0;
   unordered_map<int,int> m;
   m.insert({0,1});
   for(int i : nums) {
       sum += i;
       c += m[sum-target];
       m[sum]++;

   }
   return c;

}