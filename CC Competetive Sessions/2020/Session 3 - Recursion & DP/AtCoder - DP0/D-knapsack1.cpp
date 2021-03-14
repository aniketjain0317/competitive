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
  ll dp[n+1][w+1]={};

  // Base case already done: dp[0][j]=0;
  // i.e. in this q, base case is processed directly in the loop using dp[0][j]

  for(int i=1;i<=n  ;i++)
  {
    for(int j=1;j<=w;j++)
    {
      // dp[i][j+1] is the max val
      // at ith element (cumulative from the 1st element)
      // with exactly j weight used
// 3 8
// 3 30
// 4 50
// 5 60
      ll a = dp[i-1][j];
      ll b = 0;
      if(wt[i]<=j) b = val[i] + dp[i-1][j - wt[i]];
      dp[i][j] = max(a,b);
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }

  // OUTPUT
  cout << dp[n][w] << endl;
}
