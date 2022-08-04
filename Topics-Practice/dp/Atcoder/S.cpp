#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007;

int mod(int x, int m)
{
  x%=m;
  while(x<0) x+=m;
  return (x%m);
}

int32_t main()
{
  string s; cin >> s; int n = s.size();
  int d; cin >> d;
  if(n<5)
  {
    int ans = 0;
    int m = stoi(s);
    for(int i = 1; i<=m; i++) if(i%d==0) ans++;
    cout << ans << endl;
    return 0;
  }

  // dp[i][r] = atmost i digits, remainder r: possible numbers.
  int dp[n+1][d]={}; dp[0][0]=1;
  for(int k = 1; k<10; k++) dp[1][(k%d)]++;
  for(int i = 2; i<=n; i++)
    for(int r=0; r<d; r++)
      for(int k = 0; k<10; k++)
        dp[i][(k+r)%d]=(dp[i][(k+r)%d]+dp[i-1][r])%MOD;
  for(int i = 2; i<=n; i++)
    for(int r=0; r<d; r++)
      dp[i][r]=(dp[i][r]+dp[i-1][r])%MOD;

  // for(int i = 0; i<=n; i++) cout << dp[i][0] << endl;
  reverse(s.begin(), s.end());
  int ans = 0, curr = 0;
  for(int i = n; i; i--)
  {
    int c = s[i]-'0';
    if(i==1)
    {
      for(int k = 0; k<=c; k++) ans+= ((curr+k)%d==0);
      break;
    }
    for(int k=0; k<c; k++) ans = (ans+dp[i][mod(d-curr-k, d)])%MOD;
    curr=(curr+c)%d;
  }
  cout << ans << endl;
}
