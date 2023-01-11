#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int sum = 0;
    vector<int> postfix(n);
    postfix[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        postfix[i] = max(height[i], postfix[i + 1]);
    }

    //         for(auto i:postfix)
    //         {
    //             cout<<i<<" ";
    //         }

    //         cout<<endl;

    int i = 0;
    while (i < n - 1)
    {
        int start = height[i];
        int j = i + 1;
        int dummy = 0;
        if (height[j] < height[i])
        {
            int maxi = postfix[j];
            while (height[j] != maxi and height[j] < start)
            {
                sum += abs(min(maxi, start) - height[j]);
                j++;
            }
            i = j;
        }
        else
        {
            i++;
        }
    }
    return sum;
}

int main()
{
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
}