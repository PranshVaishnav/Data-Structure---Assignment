#include <bits/stdc++.h>
using namespace std;

int func(int ind, vector<int> &nums, int t)
{
    if (ind == 0)
    {
        if (t == nums[0] and nums[0] == 0)
            return 2;
        if (abs(t) == nums[0])
            return 1;
        return 0;
    }

    int pos = func(ind - 1, nums, t - nums[ind]);
    int neg = func(ind - 1, nums, t + nums[ind]);

    return pos + neg;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    return func(n - 1, nums, target);
}

int main()
{
    vector<int>nums={1,5,4,2,7,8,1,3};
    cout << findTargetSumWays(nums,7) << endl;
}