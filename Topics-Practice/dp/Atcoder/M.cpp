#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007;

int32_t main()
{
  int n,k; cin >> n >> k;
  int arr[n]={};
  for(int i =0; i<n; i++) cin >> arr[i];

  vector<int> dp(k+1,0);
  vector<int> cum(k+1,1);
  for(int j = 0; j<=arr[0]; j++) dp[j]=1;

  for(int i = 1; i<n; i++) for(int j = 1; j<=k; j++)
  {
    cum[j] = (cum[j-1]+dp[j])%MOD;
    dp[j] = cum[j];
    if(j-arr[i]>0) dp[j] = (dp[j] - cum[j-arr[i]-1] + MOD)%MOD;
  }
  cout << dp[k] << endl;
}
