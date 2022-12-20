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
#define bs binary_search
#define size(x) (x).size()
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

void rogenx()
{
   
    int n;
    cin >> n;
    map<int, int> mp_a;
    map<int,int> mp_b;
    vector<int> A(n+1);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int m;
    cin >> m;


    vector<int> B(m+1);
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        mp_b[B[i]]++;
    }
    int p;
    cin >> p;
    
    for(int i=0;i<n;i++)
    {
      mp_a[A[i]]++;
    }
     int gain=0;
    for(auto i:mp_b)
    {
        if(i.second-mp_a[i.first]<=0)
              gain+=i.first*i.second*p;
        else
           {
             gain-=i.first*(i.second-mp_a[i.first])*p;
             gain+=i.first*mp_a[i.first]*p;
             
           }
    }
    cout<<gain<<endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // cout << fixed << setprecision(10);
    int _ = 1, gcode = 1;
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