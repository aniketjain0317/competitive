#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;
const int INF  = 1LL<<60;

int n,m;
vector<vector<int>> adj[N]; // used vi and not pi, cuz complete edges are needed in mst
vector<vector<int>> mst;
// v[0]=weight, v[1]=source, v[2]=dest.

// min(adj[i]) will always be in MST
// almost same as djikstra
void prim()
{
  int visited[n]={};
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  for(auto edge: adj[0]) pq.push(edge); visited[0]=1;
  while(!pq.empty())
  {
    auto curr = pq.top(); pq.pop();
    if(visited[curr[2]]) continue;
    visited[curr[2]]=1;
    mst.push_back(curr);
    for(auto edge: adj[curr[2]])
      if(!visited[edge[2]])
        pq.push(edge);
  }
}

int32_t main()
{
  cin >> n >> m;
  while(m--)
  {
    int u,v,w; cin >> u >> v >> w;
    adj[u].push_back({w,u,v});
    adj[v].push_back({w,v,u});
  }

  prim();
  for(auto v: mst) cout << v[0] << " " << v[1] << " " << v[2] << endl;
}
// 8 10
// 0 2 2
// 0 3 7
// 1 2 5
// 1 3 3
// 2 4 5
// 2 5 6
// 2 6 8
// 4 6 1
// 5 6 7
// 6 7 6
