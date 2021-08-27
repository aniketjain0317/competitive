#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int arr[n]={};
    for(int i = 0; i<n; i++) cin >> arr[i];
    int ans = -1000000007;
    for(int i = 0; i<(n-1); i++) ans = max(ans, arr[i]*arr[i+1]);
    cout << ans << endl;
  }
}
