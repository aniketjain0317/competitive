#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  int n,k; cin >> n >> k;
  int arr[n];
  for(int i =0; i<n; i++) cin >> arr[i];

  vector<int> dp(n,1<<30); dp[0]=0;
  for(int i=1; i<n; i++)
  {
    for(int j = 1; j<=k; j++)
      if(i-j>=0) dp[i] = min(dp[i], dp[i-j] + abs(arr[i]-arr[i-j]));  
  }
  cout << dp[n-1] << endl;
}
