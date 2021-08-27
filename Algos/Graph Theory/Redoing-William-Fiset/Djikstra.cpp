#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pi;

// O((E+V) log v)
const int N = 100005;
const int INF = 1LL<<60;
vector<pi> adj[N];
vector<int> dist(N,INF);
vector<int> ls(N,-1);

// curr = pq.top()
// if all nodes which have cost < curr.cost have already been processed,
// and curr.cost is min among unprocessed nodes:
// curr.cost is the min cost for curr.node
void djikstra(int s)
{
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0,s}); dist[s]=0;
  while(!pq.empty())
  {
    auto p = pq.top(); pq.pop();
    if(p.first>dist[p.second]) continue;
    for(auto e: adj[p.second])
    {
      e.first += p.first;
      if(e.first<dist[e.second])
      {
        dist[e.second] = e.first;
        ls[e.second] = p.second;
        pq.push(e);
      }
    }
  }
}

// (create dist, )
// create pq

vector<int> path(int s, int d)
{
  vector<int> ans;
  if(dist[d]==INF) {ans.push_back(-1); return ans;}
  for(int c=d; c!=-1; c=ls[c]) ans.push_back(c);
  reverse(ans.begin(), ans.end());
  return ans;
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
    adj[v].push_back({w,u});
  }
  int s=1;
  djikstra(s);
  vector<int> ans = path(1,n);
  for(auto x: ans) cout << x << " ";
  cout << endl;
}
// 9 14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 8 2
// 2 5 4
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7
// 0
// ANS: 0 4 12 19 21 11 9 8 14
