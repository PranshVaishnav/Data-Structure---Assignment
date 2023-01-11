#include <bits/stdc++.h>
using namespace std;

int func(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    dp[0][0] = grid[0][0];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 and j == 0)
                continue;

            int left = INT_MAX;
            int right = INT_MAX;
            if (j - 1 >= 0)
                left = dp[i][j - 1];
            if (i - 1 >= 0)
                right = dp[i - 1][j];
            dp[i][j] = min(right, left) + grid[i][j];
        }
    }
    return dp[m][n];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return func(m - 1, n - 1, grid, dp);
}

int main()
{
   vector<vector<int>>grid={
    {1,3,1},{1,5,1},{4,2,1}
   };
    cout << minPathSum(grid) << endl;
}