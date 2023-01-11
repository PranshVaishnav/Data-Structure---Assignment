
#include <bits/stdc++.h>
using namespace std;

 int rob(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp(n+1,0);

         dp[0]=nums[0];
         for(int i=1;i<n;i++)
         {
             int a=0,b=0;
             a=dp[i-1];
             if(i-2>=0)
             b=dp[i-2];

             dp[i]=max(a,b+nums[i]);
         }
         return dp[n-1];
    }

int main()
{
    vector<int> coins = {1,2,3,1};
    cout << rob(coins)<< endl;
}