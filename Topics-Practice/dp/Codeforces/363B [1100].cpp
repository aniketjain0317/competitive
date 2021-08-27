// Easy Brute force [+2]
// WA(1): forgot case of n==k
// WA(2): n==k was actually a general case of forgetting to chmin i==k-1
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int n,k; cin >> n >> k;
  int arr[n];
  for(int i =0; i<n; i++) cin >> arr[i];
  vector<int> dp(n+1,1000000007);
  int ans = dp[0]; dp[0] = arr[0];
  int mni = -1;
  if(k == 1) ans = dp[0], mni = 0;
  for(int i = 1; i<n; i++)
  {
    dp[i] = dp[i-1]+arr[i];
    if(i==(k-1) && ans>dp[i]) ans=dp[i],mni=i;
    if(i<k) continue;
    dp[i] -= arr[i-k];
    if(ans>dp[i]) ans=dp[i],mni=i;
  }
  cout << (mni-k+2) << endl;
}
