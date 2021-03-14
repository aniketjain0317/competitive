#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
  int m,n; cin >> m >> n;
  ll arr[m];
  for(int i=0; i<m; i++) cin >> arr[i];

  sort(arr,arr+m);
  ll ans=1ll<<60;
  for(int i=0;i<=m-n;i++)
  {
    ll lmin = arr[i];
    ll lmax = arr[i+n-1];
    // ans = min(ans,lmax-lmin);
    if(lmax-lmin<ans) ans=lmax-lmin;
  }

  cout << ans << endl;
}
