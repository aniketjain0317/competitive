#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  #define int long long
  int n; cin >> n;
  int arr[n+2]={};
  for(int i =1; i<=n; i++) cin >> arr[i];
  int dp[n+1][n+1]={};
  int sgn = n&1?1:-1;
  for(int r = 0; r<n; r++) for(int i = 1; (i+r)<=n; i++)
  {
    int j = i+r;
    if(!r) dp[i][j]=sgn*arr[i];
    else if(r%2!=n%2) dp[i][j] = max(dp[i][j-1]+arr[j], dp[i+1][j]+arr[i]);
    else dp[i][j] = min(dp[i][j-1]-arr[j], dp[i+1][j] - arr[i]);
    // cout << i << " " << j << " " << dp[i][j] << endl;
  }
  cout << dp[1][n] << endl;
}
