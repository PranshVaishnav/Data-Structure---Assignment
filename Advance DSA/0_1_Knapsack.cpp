#include <bits/stdc++.h>
using namespace std;

int knapsack01(int W, int N, vector<int> &v, vector<int> &w)
{
    int DP[N + 1][W + 1]; // Defining DP

    for (int i = 0; i < N + 1; i++)
        DP[i][0] = 0;

    for (int i = 0; i < W + 1; i++)
        DP[0][i] = 0;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] <= j)
            {
               
                DP[i][j] = max(v[i - 1] + DP[i - 1][j - w[i - 1]], DP[i - 1][j]);
            }
            else
            {
           
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    return DP[N][W];
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 60, 70};
    vector<int> w = {1, 2, 3, 6, 7, 4};
    int W = 7;
    int n = sizeof(v) / sizeof(v[0]);
    cout << "Knapsack value is " << knapsack01(W, n-1, v, w);
    return 0;
}