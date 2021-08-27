#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{
  int n,p; cin >> n >> p;
  vector<vector<int>> v;
  vector<int> vals; vals.push_back(0);
  for(int i = 0; i<n; i++)
  {
    int x,y,k; cin >> x >> y >> k; y++;
    v.push_back({y,x,k});
    vals.push_back(x);
    vals.push_back(y);
  }

  sort(vals.begin(), vals.end());
  int curr = 0;
  map<int,int> id;
  for(auto k: vals) id[k]=curr++;
  for(auto &x: v) x[0]=id[x[0]], x[1] = id[x[1]];
  int sz = curr;

  sort(v.begin(), v.end());
  int dp[p+1][sz]={};
  for(int j = 1; j<=p; j++)
  {
    int i = 0;
    for(int k = 1; k<sz; k++)
    {
      dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
      if(v[i][0]==k)
        dp[j][k] = max(dp[j][k], dp[j-1][v[i][1]] + v[i][2]), i++;
    }
  }

  int ans = dp[p][sz-1];
  cout << ans << endl;
}
x-r=y+r=k
8 2
2 5 1 3 6 4 8 7
7 5 2 1 7 2 7 1 // dist from 1 2 3 4 5 6 7 8
2 6 3 6 2 1 6 6 // dist from 8 7 6 5 4 3 2 1
