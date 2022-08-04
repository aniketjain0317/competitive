#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXV = 1LL<<60;

int32_t main()
{
  int n; cin >> n;
  int arr[n+2]={};aA
  for(int i =1; i<=n; i++) cin >> arr[i];
  int cum[n+1]={};
  for(int i =1; i<=n; i++) cum[i] = cum[i-1]+arr[i];

  int dp[n+1][n+1]={};
  for(int r = 1; r<n; r++) for(int i = 1; (i+r)<=n; i++)
  {
    int j = i+r;
    dp[i][j] = MAXV;
    for(int k= 0; k<j; k++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
    dp[i][j]+=cum[j]-cum[i-1];
  }
  cout << dp[1][n] << endl;
}
// dp[i][j] = min(dp[i][j-k] + dp[j-k][j]) + cum[i][j]
// MCM
