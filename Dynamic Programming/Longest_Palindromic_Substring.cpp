#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
         //Marking all single character palindromic substring as 1
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }

        //Marking all double character palindromic substring as 1
        
        for(int i=1;i<n;i++)
        {
           if(s[i]==s[i-1])
           dp[i-1][i]=2;
        }
        int l;
        int r;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i][j]>=1)
                {
                    l=i;
                    r=j;
                    int cnt=-1;
                    while(l>=0 and r<n and s[l]==s[r])
                    {
                       cnt++;
                       l--;
                       r++;
                    }
                    dp[l+1][r-1]=dp[i][j]+2*cnt;
                }
            }
        }


        l=0;r=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                 if(dp[i][j]>maxi)
                 {
                     maxi=dp[i][j];
                     l=i;
                     r=j;
                 }
            }
        }

        return s.substr(l,r-l+1);
    }


int main()
{
    string s="abbbabcbbaa";
    cout<<longestPalindrome(s)<<endl;
}