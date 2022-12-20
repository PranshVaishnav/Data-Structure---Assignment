#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        string ans = "";
        if (a % 3 == 0 or a % 3 == 2)
        {
            while (a > 0)
            {
                ans.push_back('2');
                a = a - 2;
                if (a != 0)
                {
                    ans.push_back('1');
                    a--;
                }
            }
        }
        else
        {
            while (a > 0)
            {
                ans.push_back('1');
                a = a - 1;
                if (a != 0)
                {
                    ans.push_back('2');
                    a -= 2;
                }
            }
        }
        cout << ans << endl;
    }
}
