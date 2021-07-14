#include <bits/stdc++.h>
using namespace std;
#define int long long

#define x first
#define y second

typedef pair<int,int> pi;

int dist(pi p1, pi p2)
{
  return abs(p1.x - p2.x) + abs(p1.y-p2.y);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while(t--)
  {
    int n,m,xx,yy; cin >> n >> m >> xx >> yy;
    pi h(xx,yy);
    int ans = -1, fi = -1, fj = -1;
    pi corners[4] = {{1,1}, {1,m}, {n, m}, {n, 1}};
    for(int i = 0; i<4; i++) for(int j = 0; j<4; j++)
    {
      int val = dist(h, corners[i]) + dist(corners[i], corners[j]) + dist(corners[j], h);
      if(val>=ans)
      {
        ans = val; fi = i; fj = j;
      }
    }
    // cout << "AAA ";
    cout << corners[fi].x << " " << corners[fi].y << " ";
    cout << corners[fj].x << " " << corners[fj].y << endl;
  }
}
