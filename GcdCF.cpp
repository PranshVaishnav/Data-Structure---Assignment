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

#define MAXN   10000001
 
// stores smallest prime factor for every number
int spf[MAXN];


// #ifndef ONLINE_JUDGE
// #include <bits/debug.h>
// #else
// #define debug(x)
// #endif
/*----------------------------------------------------------------------------------------*/


void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 



void primeFactors(int x, vector<int> &fact)
{
     while (x != 1)
    {
        fact.push_back(spf[x]);
        x = x / spf[x];
    }
}

void rogenx()
{

    int a;
    cin >> a;
    int b;
    cin >> b;

    if (abs(a - b) == 1)
    {
        cout << -1 << endl;
        return;
    }
    if(a==1 and b==1)
    {
        cout << 1 << endl;
        return;
    }
    
    

    if(__gcd(a,b)!=1)
    {
        cout<<0<<endl;
        return;
    }

    if (a < b)
        swap(a, b);

    // Now a is Bigger than b
    // We will now get the difference of a-b;
    // store it in x
    int x = a - b;
    vector<int> fact;
    primeFactors(x, fact);

    int ans = INT_MAX;
    for (auto i : fact)
    {
        ans = min(ans, i - (a % i));
    }
    cout << ans << endl;
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
    cin >> _;
    sieve();
    while (_--)
    {
        //cout << "Case #" << gcode++ << ": ";
        
        rogenx();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << "ms" << nline;
#endif
    return 0;
}