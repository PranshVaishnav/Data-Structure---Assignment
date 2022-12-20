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

int strcmpF(char s[50], char m[50])
{
    int n1 = 50;
    int n2 = 50;

    if (n1 == n2 and s == m)
        return 0;

    int i = 0;
    while (i < min(n1, n2))
    {
        if (s[i] != m[i])
        {
            return s[i] - m[i];
        }
        i++;
    }
    if (i == n1)
    {
        return m[i] - '\0';
    }
    else
    {
        return s[i] - '\0';
    }
}

char *strcpy(char s[50], char m[50])
{

    for (int i = 0; i < 50; i++)
    {
        m[i] = s[i];
        if (s[i] == '\0')
        {
            m[i] = s[i];
            break;
        }
    }
    return m;
}

void sorti(string s)
{
    vector<pair<int, int>> ch(27,{0,0});
    for (auto i : s)
    {
        if(i==' ')continue;
        
        if(i>'Z')ch[i - 'a'].first++;
        else
        ch[i - 'A'].second++;
    }

    string ans="";

    for (int i = 0; i < 26; i++)
    {
        //cout<<ch[i].first<<ch[i].second<<endl;
        while (ch[i].first != 0)
        {
            ans.push_back(char(i + 'a'));
            ch[i].first--;
        }
        while (ch[i].second != 0)
        {
            ans.push_back(char(i + 'A'));
            ch[i].second--;
        }
    }

    cout<< ans;
}

void rogenx()
{

    char s1[50] = "Hello";

    char m1[50] = "hello";

    char m2[50] = "";

    string s = "Helllo Wprds";
    int res = strcmp(s1, m1);
    cout << res << endl;
    cout << strcmpF(s1, m1) << endl;
    cout << *strcpy(s1, m2) << endl;
    for (auto i : m2)
        cout << i << " ";
    cout << endl;

    cout << s << " --> ";
    sorti(s);
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