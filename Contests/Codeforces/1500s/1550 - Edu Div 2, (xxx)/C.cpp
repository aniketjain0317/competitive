#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int a[n];
    for(int i =0; i<n; i++) cin >> a[i];
    int ans  = n + (n-1);

    for(int i =0; i<=(n-3); i++)
    {
      if(a[i+2]>= a[i+1] && a[i+1]>=a[i]) continue;
      else if(a[i+2]<=a[i+1] && a[i+1]<=a[i]) continue;
      else ans++;
    }

    for(int i =0; i<=(n-4); i++)
    {
      if(a[i]<a[i+1] && a[i+2]<a[i] && a[i+3]<a[i+1] && a[i+2]<a[i+3]) ans++;
      if(a[i]>a[i+1] && a[i+2]>a[i] && a[i+3]>a[i+1] && a[i+2]>a[i+3]) ans++;
    }

    cout << ans << endl;
  }
}
//
