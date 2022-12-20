#ifdef ONLINE_JUDGE
#pragma GCC optimize('Ofast')
#endif

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define nline '\n'
#define mm (9*1e18)
#define mp make_pair
#define pb push_back
#define int long long
#define mn ((-9)*1e18)
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
using namespace chrono;
#define bs binary_search
#define double long double
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);

// #ifndef ONLINE_JUDGE
// #include <bits/debug.h>
// #else
// #define debug(x)
// #endif
/*----------------------------------------------------------------------------------------*/


void rogenx() {
    stack<int>st;
    stack<int>ans;
    vector<int>arr={7,12,6,4,13,5};
    int n=arr.size();
    vector<int>freq(n,0);
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        cout<<arr[i]<<endl;

        if(arr[i]>=st.top())
        {
            st.push(arr[i]);
        }
        else {
            while(!st.empty() and arr[i]<st.top())
            {
                int x=st.top();
                st.pop();
                ans.push(x);
            }
            cout<<endl;
            st.push(arr[i]);
            freq[i]=ans.size();
            while(!ans.empty())
            {
                int y=ans.top();
                ans.pop();
                st.push(y);
            }
            
            cout<<endl;
        }

    }
    
        for(auto i:freq)
        cout<<i<<" ";
}


int32_t main() {
#ifndef ONLINE_JUDGE
freopen("error.txt", "w", stderr);
#endif
fastio();
auto start1 = high_resolution_clock::now();
// cout << fixed << setprecision(10);
int _ = 1, gcode = 1;
cin >> _;
while (_--) {
//cout << "Case #" << gcode++ << ": ";
rogenx();
}
auto stop1 = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
cerr << "Time: " << duration . count() / 1000 << "ms" << nline;
#endif
return 0;
}