#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;
const int INF  = 1LL<<60;

class DisjSet
{
public:
  int n;
  vector<int> parent;
  vector<int> sz;

  DisjSet(int m)
  {
    n=m;
    parent.resize(n,0);
    sz.resize(n,1);
    for(int i =0; i<n; i++) parent[i]=i;
  }

  int find(int x)
  {
    if(parent[x]!=x) parent[x] = find(parent[x]);
    return parent[x];
  }

  int merge(int u, int v)
  {
    int x = find(u), y = find(v);
    if(x==y) return 0;
    if(sz[x]<sz[y]) swap(x,y);
    parent[y] = x;
    sz[x]+=sz[y];
    return 1;
  }
};

int n,m;
vector<vector<int>> adj[N];
vector<vector<int>> mst;
vector<vector<int>> edges;



void kruskal()
{
  sort(edges.begin(), edges.end());
  DisjSet dsu(n);
  for(auto edge: edges)
    if(dsu.merge(edge[1], edge[2]))
      mst.push_back(edge);
}


int32_t main()
{
  cin >> n >> m;
  while(m--)
  {
    int u,v,w; cin >> w >> u >> v;
    adj[u].push_back({w,u,v});
    adj[v].push_back({w,v,u});
    edges.push_back({w,u,v});
  }

  kruskal();
  for(auto v: mst) cout << v[0] << " " << v[1] << " " << v[2] << endl;
}
// 9 14
// 1         7      6
// 2         8      2
// 2         6      5
// 4         0      1
// 4         2      5
// 6         8      6
// 7         2      3
// 7         7      8
// 8         0      7
// 8         1      2
// 9         3      4
// 10        5      4
// 11        1      7
// 14        3      5
