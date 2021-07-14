#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100005;

int n,m;
vector<int> adj[N];
vector<int> roots;
int visited[N]={};
int val[N]={};

void dfs(int node)
{
  visited[node]=1;
  for(auto child: adj[node])
  {
    if(!visited[child]) dfs(child);
    val[node] = max(val[node], val[child]+1);
  }
}

int32_t main()
{
  cin >> n >> m;
  int used[n+1]={};
  for(int i = 0; i<m; i++)
  {
    int u,v; cin >> u >> v;
    adj[u].push_back(v);
    used[v]=1;
  }
  for(int i=1; i<=n; i++) if(!used[i]) roots.push_back(i);

  for(auto x: roots)
    dfs(x);
  int ans = 0;
  for(auto x: roots) ans = max(ans, val[x]);
  cout << ans << endl;
}
