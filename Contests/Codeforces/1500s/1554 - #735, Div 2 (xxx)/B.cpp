// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define int long long

int INF = 1000000007;
int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n,k; cin >>n >> k;
    int arr[n]={};
    for(int i = 0; i<n; i++) cin >> arr[i];
    int st = 0;
    if(n>1000) st = n-400;
    int ans = -INF;
    for(int i = st; i<n; i++) for(int j =i+1; j<n; j++)
    {
      int val = (i+1)*(j+1) - k*(arr[i]|arr[j]);
      ans = max(ans,val);
    }
    cout << ans << endl;
  }
}
