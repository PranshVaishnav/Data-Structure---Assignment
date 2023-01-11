#include <bits/stdc++.h>
using namespace std;


 int fib(int n) {
        vector<int>dp(n+1,0);
        
        if(n==0) return 0;
        dp[0]=0;
        dp[1]=1;
 
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }

    int main()
{
    cout<<fib(15)<< endl;
}