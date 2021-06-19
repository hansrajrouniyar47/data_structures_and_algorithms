
/*
https://binarysearch.com/problems/Ugly-Number-Sequel
*/

int solve(int n) {
   int dp[n+2];
        dp[1] =1;
        int p2 =1, p3 = 1, p5 = 1;
        for(int i =2; i<= n+1 ; i++){
            int f1 =  2* dp[p2];
            int f2 = 3* dp[p3];
            int f3 = 5* dp[p5];
            int min_ = min(f1, min(f2, f3));
            dp[i] = min_;
            if(min_ == f1) p2++;
            if(min_ == f2) p3++;
            if(min_ == f3) p5++;
         }
        return dp[n+1];
}