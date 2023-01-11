#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &nums, vector<int> &dp)
{
    // BAse Case

    if (i == 0)
    {
        return 1;
    }

    if (dp[i] != -1)
        return dp[i];
    // Hypothesis
    int maxi = 0;
    // if picked
    for (int j = i - 1; j >= 0; j--)
    {
        if (nums[j] < nums[i])
            maxi = max(maxi, solve(j, nums, dp));
    }
    maxi++;

    return dp[i] = maxi;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 1;
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
        maxi = max(solve(i, nums, dp), maxi);

    return maxi;
}

int main()
{
    vector<int> coins = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(coins) << endl;
}