class Solution {
public:
    vector<int> dp;
    int func(int n){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        if(n==0) return dp[n]=1;
        return dp[n] = func(n-1) + func(n-2);
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return func(n);
    }
};
