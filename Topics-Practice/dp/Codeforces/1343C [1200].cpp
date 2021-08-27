// AC (+0)
// idk why the tag had 2 pointers in it

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int arr[n+1]={}; for(int i = 1; i<=n; i++) cin >> arr[i];
    int ans = 0, curr = arr[1];
    int cs = arr[1]>0?1:-1;
    for(int i = 1; i<=n; i++)
    {
      int cs2 = arr[i]>0?1:-1;
      if(cs!=cs2)
      {
        cs = cs2;
        ans += curr;
        curr = arr[i];
      }
      else curr = max(curr, arr[i]);
    }
    ans += curr;
    cout << ans << endl;
  }
}
