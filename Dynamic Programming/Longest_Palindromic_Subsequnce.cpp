#include <bits/stdc++.h>
using namespace std;

 int maxi=INT_MIN;
    int lcs(int i,int j,string &p,string &s,vector<vector<int>>&dp)
    {
       if(i<0 || j<0)
          return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(p[i]==s[j])
            return dp[i][j]=1+lcs(i-1,j-1,p,s,dp);
        
        return dp[i][j]=max(lcs(i,j-1,p,s,dp),lcs(i-1,j,p,s,dp));
        
    }
    
    int longestPalindromeSubseq(string s) {
        string p=s;
        reverse(s.begin(),s.end());
        int n1=p.size();
        vector<vector<int>>dp(n1+1,vector<int>(n1+1,-1));

        return lcs(p.size()-1,s.size()-1,p,s,dp);
        
       
    }

 int main()
{
    cout<<longestPalindromeSubseq("absabbaabb")<< endl;
}