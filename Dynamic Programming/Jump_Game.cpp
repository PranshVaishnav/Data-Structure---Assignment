
#include <bits/stdc++.h>
using namespace std;


bool func(int i, vector<int> &nums, int &n, vector<int> &dp)
{
    // Base Case
    if (i >= n - 1)
    {
        return true;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }
    // Hypothetical
    bool ans = false;
    for (int j = 1; j <= nums[i]; j++)
    {
        if (func(i + j, nums, n, dp))
        {
            ans = true;
            break;
        }
    }

    return dp[i] = ans;
}

bool canJump(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return func(0, nums, n, dp);
}

int main()
{
     vector<int>nums={2,3,1,1,4};
     cout << canJump(nums) << endl;
}