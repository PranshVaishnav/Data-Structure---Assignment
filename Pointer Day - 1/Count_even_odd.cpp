#include <bits/stdc++.h>
using namespace std;

int findEven(int *arr, int n)
{

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) & 1)
            cnt++;
    }
    return cnt;
}

int findOdd(int *arr, int n)
{

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (!(*(arr + i) & 1))
            cnt++;
    }
    return cnt;
}

int main()
{
    int arr[] = {27, 33, 42, 96, 14, 24, 33};
    int n = (sizeof(arr) / sizeof(arr[0]));
    cout << findEven(arr, n) << endl;
    cout << findOdd(arr, n);
}