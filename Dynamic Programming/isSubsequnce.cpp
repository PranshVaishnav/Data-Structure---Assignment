#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{

    int n1 = s.size();
    int n2 = t.size();
    int i = 0;
    for (int j = 0; j < n2; j++)
    {
        if (t[j] == s[i])
        {
            i++;
        }
    }

    if (i >= n1)
        return true;
    return false;
}

int main()
{
    cout << isSubsequence("abc","ahbgdc") << endl;
}