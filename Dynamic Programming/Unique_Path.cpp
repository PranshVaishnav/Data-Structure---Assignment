
#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    // if(i==0 and j==0)
    //     return 1;

    if (i < 0 || i > m - 1 || j < 0 || j > n - 1)
        return 0;

    //         if(dp[i][j]!=-1)
    //             return dp[i][j];

    //         int a=func(i,j-1,m,n,dp);
    //         int b=func(i-1,j,m,n,dp);

    //         return dp[i][j]=a+b;

    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                continue;

            int right = 0;
            int left = 0;
            if (j - 1 >= 0)
                right = dp[i][j - 1];
            if (i - 1 >= 0)
                left = dp[i - 1][j];

            dp[i][j] = left + right;
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return func(m - 1, n - 1, m, n, dp);
}

int main()
{
    int m = 3;
    int n = 7;
    cout << uniquePaths(m, n) << endl;
}