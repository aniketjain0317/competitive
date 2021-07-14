#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100005;
const int MOD = 1000000007;

int n;
vector<int> edges[N];
vector<int> adj[N];
vector<bool> visited(N,0);
vector<vector<int>> dp(N, vector<int>(2,1));


void root(int node)
{
  visited[node]=1;
  for(auto &child: edges[node])
  {
    if(!visited[child])
    {
      adj[node].push_back(child);
      root(child);
    }
  }
}

int dfs(int node)
{
  for(auto &child: adj[node])
  {
    dp[node][0] = (dp[node][0]*dfs(child))%MOD;
    dp[node][1] = (dp[node][1]*dp[child][0])%MOD;
  }
  return (dp[node][0]+dp[node][1])%MOD;
}


int32_t main()
{
  cin >> n;
  for(int i =1; i<n; i++)
  {
    int u,v; cin >> u >> v;
    edges[v].push_back(u);
    edges[u].push_back(v);
  }
  root(1);
  int ans = dfs(1);
  cout << ans << endl;
}
