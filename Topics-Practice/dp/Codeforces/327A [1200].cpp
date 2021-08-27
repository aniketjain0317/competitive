// AC(+0)
// Easy if O(n^2/n^3) allowed
// DP with pref/suff in O(n)

#include <bits/stdc++.h>
using namespace std;
// #define int long long

int32_t main()
{
  int n; cin >> n;
  int arr[n+1];
  for(int i = 1; i<=n; i++) cin >> arr[i];
  int pref[n+1]={}, suff[n+2]={};
  for(int i = 1; i<=n; i++) pref[i]=pref[i-1]+arr[i];
  for(int i = n; i>=0; i--) suff[i]=suff[i+1]+arr[i];
  int curr = 0, ans = 0;
  for(int i = 1; i<=n; i++)
  {
    curr = max(curr,pref[i-1]);
    curr += (!arr[i]);
    ans = max(ans, curr+suff[i+1]);
  }
  cout << ans << endl;
}
