#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while(t--)
  {
    int xmax, ymax; cin >> xmax >> ymax;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int x,y; cin >> x >> y;
    int xlen = x2-x1, ylen = y2-y1;
    int ans = INT_MAX;
    if(x+xlen<=xmax)
    {
      ans = min(ans, max(0LL,x-x1));
      ans = min(ans, max(0LL,x+x2-xmax));
    }
    if(y+ylen<=ymax)
    {
      ans = min(ans, max(0LL,y-y1));
      ans = min(ans, max(0LL,y+y2-ymax));
    }
    if(ans==INT_MAX) ans = -1;
    cout << ans << endl;
  }
}
