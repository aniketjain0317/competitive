#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pi;
const int N = 100005;
const int INF = 1LL<<60;

vector<pi> adj[N];
vector<int> dist(N,INF);

void bellmanFord(int s, int n)
{
  dist[s]=0;
  for(int i = 0; i<n-1; i++)
    for(int node = 0; node<=n; node++)
      for(auto edge: adj[node])
        dist[edge.second] = min(dist[edge.second], dist[node]+edge.first);

  for(int i = 0; i<n-1; i++)
    for(int node = 0; node<=n; node++)
      for(auto edge: adj[node])
        if(dist[edge.second]>dist[node]+edge.first) dist[edge.second]=-INF;
}


int32_t main()
{
  int n,m;
  cin >> n >> m;
  for(int i = 0; i<m; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
    // adj[v].push_back({w,u});
  }
  int s; cin >> s;
  bellmanFord(s,n);
  for(int i = 0; i<=n; i++) cout << dist[i] << " "; cout << endl;
}
