#ifdef ONLINE_JUDGE
#pragma GCC optimize('Ofast')
#endif

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define nline '\n'
#define mm (9 * 1e18)
#define mp make_pair
#define pb push_back
#define int long long
#define mn ((-9) * 1e18)
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
using namespace chrono;
// #define bs binary_search
// #define size(x) (x).size()
#define double long double
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i, a, b) for (int i = a; i < b; i++)
#define rfora(i, a, b) for (int i = b - 1; i >= a; i--)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// #ifndef ONLINE_JUDGE
// #include <bits/debug.h>
// #else
// #define debug(x)
// #endif
/*----------------------------------------------------------------------------------------*/


void Merge(vector<int>&arr,int l,int mid,int r)
{
    int sizel=mid-l+1;
    int sizer=r-mid;
   vector<int>left(sizel,0);
   vector<int>right(sizer,0);

   int k=l;
   int i=0;
   int j=0;

   for( i=0;i<left.size();i++)
   {
    left[i]=arr[k++];
   }
   for(i=0;i<right.size();i++)
   {
    right[i]=arr[k++];
   }
 k=l;
 i=0;
 j=0;
   while(i<sizel and j<sizer)
   {
      if(left[i]<right[j])
      {
        arr[k++]=left[i++];
      }
       else
      {
        arr[k++]=right[j++];
      }
   }
   while(i<sizel)
   {
     arr[k++]=left[i++];
   }
   while(j<sizer)
   {
     arr[k++]=right[j++];
   }
}

void MergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        MergeSort(arr,l,mid);
        MergeSort(arr, mid+1, r);
        Merge(arr,l, mid, r);
    }
}

void rogenx()
{

    vector<int> arr = {4, 2, 7, 6, 8, 3, 1, 5};
    int l = 0;
    int r = arr.size() - 1;
    MergeSort(arr, l, r);
    for(auto i:arr)
    cout<<i<<" ";
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);wad
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // cout << fixed << setprecision(10);
    int _ = 1, gcode = 1;
    // cin >> _;
    while (_--)
    {
        // cout << "Case #" << gcode++ << ": ";
        rogenx();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << "ms" << nline;
#endif
    return 0;
}

