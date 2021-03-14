// AC

#include <bits/stdc++.h>
using namespace std;

#define INF 1e18L+5
typedef long long int ll;

int main()
{
  // INPUT
  int n; ll w; cin >> n >> w;
  ll wt[n+1];
  int  val[n+1];
  // vmax = max val possible
  int vmax=0;
  for(int i=1;  i<=n; i++)
  {
    cin >> wt[i] >> val[i];
    vmax +=val[i];
  }

  // INIT
  ll dp[vmax+1]={};

  for(int i=1;i<=vmax;i++) dp[i]=INF;
  // Base case already done: dp[0]=0;
  // 3 8
  // 3 30
  // 4 50
  // 5 60

  for(int i=1;i<=n;i++)
  {
    for(int k = vmax; k>=val[i]; k--)
    {
      dp[k] = min(dp[k],dp[k-val[i]]+wt[i]);
      // cout << k << " " << val[i] << " " << dp[k] << endl;
    }
  }

  // OUTPUT
  int ans=0;
  for(int i=1;i<=vmax;i++)
  {
    if(dp[i]<=w) ans=i;
  }
  cout << ans << endl;
}
