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

vector<int>priority;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


int findK(vector<int>arr,int k)
{
    for(int i=0;i<arr.size();i++)
    {
        priority.push_back(arr[i]);
        int j=i;
        while( priority[(j-1)/2]>priority[j])
        {
            swap(priority[(j-1)/2],priority[j]);
        }
    }
    for(int i=0;i<priority.size();i++)
    cout<<priority[i]<<" ";

    cout<<endl;
    return priority[k-1];
}

int dequeue(vector<int>priority)
{
    swap(priority[0],priority[priority.size()-1]);
    priority.pop_back();
    int i=0;
    while(priority[2*i+1])

}



void rogenx() {
   vector<int>arr={5,1,7,8,2,4,6};
   int k;
   cin>>k;
   cout<<findK(arr,k);
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