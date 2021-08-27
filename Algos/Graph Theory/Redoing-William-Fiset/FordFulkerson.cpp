#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100;
const int INF = 1LL<<60;

int n,m;
map<int,int> adj[N]; //v[0]=child, v[1]=cap
map<int,int> flow[N]; //child, cap, curr
int source, sink;

int visited[N]={};
int dfs(int node, vector<int> &path)
{
  if(!path.empty() && path.back()==sink) return 1;
  path.push_back(node);
  visited[node]=1;
  if(node==sink) return 1;
  for(auto p: adj[node])
  {
    int child = p.first;
    int val = adj[node][child] - flow[node][child];
    if((!visited[child]) && val)
      if(dfs(child, path))
        return 1;
  }
  path.pop_back();
  return 0;
}

int fordFulkerson()
{
  vector<int> path;
  while(dfs(source, path))
  {
    int val = INF;
    for(int i = 1; i<path.size(); i++)
      val = min(val, adj[path[i-1]][path[i]] - flow[path[i-1]][path[i]]);

    for(int i = 1; i<path.size(); i++)
    {
      flow[path[i-1]][path[i]] += val;
      flow[path[i]][path[i-1]] -= val;
    }

    for(int i = 0; i<n; i++) visited[i]=0;
    path.clear();
    dfs(source, path);
  }
  int ans = 0;
  for(auto p: flow[source]) ans += p.second;
  return ans;
}

int32_t main()
{
  cin >> n >> m;
  while(m--)
  {
    int u,v,c; cin >> u >> v >> c;
    adj[u][v] = c;
    adj[v][u] += 0;
    flow[u][v] = 0;
    flow[v][u] = 0;
  }
  cin >> source >> sink;
  int ans = fordFulkerson();
  cout << ans << endl;
  for(int i = 0; i<n; i++)
    for(auto p: adj[i]) if(p.second)
      cout << i << " " << p.first << " "<<flow[i][p.first] << "/" << p.second << endl;
}
