#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  int n, w; cin >> n >> w;
  vector<int> wt(n+1,0), val(n+1,0);
  for(int i =1; i<=n; i++) cin >> wt[i] >> val[i];
  int MAXV = 0;
  for(int i = 1; i<=n; i++) MAXV += val[i];

  int dp[n+1][MAXV+1]={};
  for(int j=1; j<=MAXV; j++) dp[0][j]=w+1;
  for(int i = 1; i<=n; i++) for(int j = 0; j<=MAXV; j++)
  {
    dp[i][j] = dp[i-1][j];
    if(j-val[i]>=0) dp[i][j] = min(dp[i][j], dp[i-1][j-val[i]]+wt[i]);
  }

  int ans = 0;
  for(int j = 0; j<=MAXV; j++) if(dp[n][j]<=w) ans = j;
  cout << ans << endl;
}
