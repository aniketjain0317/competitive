#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  int n; cin >> n;
  int v[n+1][3]={};
  for(int i =1; i<=n; i++) for(int j = 0; j<3; j++) cin >> v[i][j];

  int dp[n+1][3]={};
  for(int i =1; i<=n; i++)
    for(int j = 0; j<3;j++)
      dp[i][j] = v[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
  int ans = 0;
  for(int j =0; j<3; j++) ans = max(ans, dp[n][j]);
  cout << ans << endl;
}
