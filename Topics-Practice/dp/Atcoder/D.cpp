#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  int n,w; cin >> n >> w;
  vector<int> wt(n+1,0), val(n+1,0);
  for(int i = 1; i<=n; i++) cin>> wt[i] >> val[i];

  vector<int> dp(w+1,0);
  for(int i =1; i<=n; i++)
  {
    vector<int> nw(dp);
    for(int j = 0; j<=w; j++)
    {
      // dp[i][j] = dp[i-1][j];
      if(j-wt[i]>=0) nw[j] = max(nw[j], dp[j-wt[i]]+val[i]);
    }
  }
  cout << dp[w] << endl;
}
