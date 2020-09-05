// AC

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001
typedef long long int ll;

int main()
{
  // INPUT
  int n,w; cin >> n >> w;
  int wt[n+1];
  ll  val[n+1];
  for(int i=0;  i<n; i++) cin >> wt[i+1] >> val[i+1];

  // INIT
  ll dp[w+1]={};

  // Base case already done: dp[0]=0;

  for(int i=1;i<=n;i++)
  {
    for(int k = wt[i]; k<=w; k++)
    {
      // dp[k] = is the max val with weight k, and upto i items included
      dp[k] = max(dp[k],dp[k-wt[i]]+val[i]);
      cout << k << " " << wt[i] << " " << dp[k] << endl;
    }
  }

  // OUTPUT
  ll answer = *max_element(dp,dp+w+1);
  cout << answer << endl;
}
