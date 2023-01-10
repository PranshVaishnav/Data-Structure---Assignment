#include <bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, int seg[], vector<int> arr)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid, seg, arr);
    build(2 * ind + 2, mid + 1, high, seg, arr);
    seg[ind] = seg[2 * ind + 1] & seg[2 * ind + 2];
}

int query(int ind, int low, int high, int l, int r, int seg[])
{
    // no overlap
    // return INT_MAX;

    if (r < low || l > high)
        return INT_MIN ;

    // Complete overlap
    if (l <= low and r >= high)
        return seg[ind];

    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r, seg);
    int right = query(2 * ind + 2, mid+1, high,l, r, seg);
    if(left==INT_MIN and right==INT_MIN)
    return 0;
    else if(left==INT_MIN and right!=INT_MIN)
    return right;
    else if(left!=INT_MIN and right==INT_MIN)
    return left;
    return left & right;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int seg[4 * n];
    // ind,low,high,segment array,default array;
    build(0, 0, n - 1, seg, arr);
  
 
    
    int q;
    cin >> q;
    while (q--)
    {
        int l;
        cin >> l;
        int r;
        cin >> r;
        cout<<query(0, 0, n - 1, l, r, seg)<<endl;
    }
}