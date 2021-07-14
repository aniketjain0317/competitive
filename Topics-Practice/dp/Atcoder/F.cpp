#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  string s,t; cin >> s >> t;
  int n = s.size(), m = t.size();
  int dp[n+1][m+1]={};
  pair<int,int> ch[n+1][m+1]={};
  // dp[i][j] = max LCS until now.
  for(int i = 0; i<=n; i++) for(int j = 0; j<=m; j++)
  {
    if(!i || !j) {ch[i][j]={-1,-1}; continue;}
    int a = dp[i-1][j];
    int b = dp[i][j-1];
    int c = 0;
    if(s[i-1]==t[j-1]) c = dp[i-1][j-1]+1;
    if(c>a && c>b) dp[i][j]=c, ch[i][j] = {i-1,j-1};
    else if(b>a && b>=c) dp[i][j]=b, ch[i][j] = ch[i][j-1];
    else dp[i][j]=a, ch[i][j]=ch[i-1][j];
  }
  string ans;
  int x = n, y = m;
  while(true)
  {
    int a = ch[x][y].first, b = ch[x][y].second;
    if(a==-1) break;
    ans += s[a];
    x=a,y=b;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
