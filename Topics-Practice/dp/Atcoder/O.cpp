#include <bits/stdc++.h>
using namespace std;

// #define int long long
const int MOD = 1000000007;

int32_t main()
{
  int n; cin >> n;
  vector<int> adj[n];
  int c = 0;
  for(int i = 0; i<n; i++) for(int j = 0; j<n; j++)
  {
    scanf("%d",&c);
    if(c) adj[i].push_back(j);
  }
  int m = 1<<n;
  vector<int> dp(m,0);
  for(auto &j: adj[0]) dp[1<<j]=1;

  for(int i = 1; i<n; i++)
  {
    // masks s.t. i bits set
    // 11100000
    unsigned int v = (1<<i) - 1, mx = v;
    while(mx<m) mx<<=1; mx>>=1;
    while(true)
    {
      for(auto &j: adj[i])
        if((v&(1<<j))==0)
          dp[v|(1<<j)] = (dp[v|(1<<j)]+dp[v])%MOD;

      if(v==mx) break;
      unsigned int t = v | (v - 1);
      v = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    }
  }
  printf("%d\n",dp[(1<<n)-1]);
}
