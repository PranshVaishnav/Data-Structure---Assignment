#include <bits/stdc++.h>
using namespace std;

int func(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    // Base Case
    if (amount == 0)
        return 0;
    if (ind < 0 || amount < 0)
        return 1e8;

    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int pick = 1 + func(ind, amount - coins[ind], coins, dp);
    int notpick = func(ind - 1, amount, coins, dp);

    return dp[ind][amount] = min(pick, notpick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int ans = func(n - 1, amount, coins, dp);
    if (ans == 1e8)
        return -1;

    return ans;
}

int main()
{
    vector<int>coins={1,2,5};
    int target=11;
    cout << coinChange(coins,target) << endl;
}