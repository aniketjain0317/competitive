#include <bits/stdc++.h>
using namespace std;

string maxs(string a, string b)
{
  return a.length() > b.length() ? a : b;
}

int main()
{
  // INPUT
  string s,t; cin >> s >> t;
  int m = s.length(), n = t.length();

  // INIT
  string dp[3000][3000];

  // BASE CASE DONE:
  for(int i=0;i<m;i++) for(int j=0;j<n;j++) dp[i][j]="";

  for(int i =1;i<=m; i++)
  {
    for(int j=1;j<=n; j++)
    {
      // dp[i][j] is the lcs of two strings s[0...i-1] and t[0...j-1]
      if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + s[i-1];
      else dp[i][j] = maxs(dp[i-1][j],dp[i][j-1]);
      // cout <<i<<" "<<j<<" "<< dp[i][j] << endl;
    }
  }

  // OUTPUT
  cout << dp[m][n] << endl;
}
