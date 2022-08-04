// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, ans;
vector<vector<int>> adj;
vector<int> parent;
vector<int> values;
set<pair<int,int>> pathValues;
map<int, int> pathMap;
vector<map<int,int>> nodeMap;

void dfs1(int node)
{
  int value = values[node];
  pathValues.insert({value, node});
  auto &p = *pathValues.upper_bound({value,node});
  ans += nodeMap[p.second][value]++;
  for(auto &child: adj[node]) if(parent[node]!=child)
  {
    parent[child] = node;
    dfs1(child);
  }
  pathValues.erase({value, node});
}

void dfs2(int node)
{
  for(auto &p: nodeMap[node])
  {
    ans += p.second * pathMap[p.first];
    pathMap[p.first] += p.second;
  }
  for(auto &child: adj[node]) if(parent[node]!=child)
    dfs2(child);
  for(auto &p: nodeMap[node])
    pathMap[p.first] -= p.second;
}


void solve()
{
  cin >> n; ans = 0;
  adj.clear(); parent.clear(); values.clear();
  pathValues.clear(); pathMap.clear(); nodeMap.clear();
  adj.resize(n);
  nodeMap.resize(n);
  parent.resize(n,0);
  for(int i = 0; i<(n-1); i++)
  {
    int u,  v; cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i<n; i++)
  {
    int x; cin >> x;
    values.push_back(x);
  }
  pathValues.insert({10000000, 0});
  dfs1(0);
  dfs2(0);
  cout << ans << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int t; cin >> t; while(t--)
  {
    solve();
  }
}
// Input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5
// 2 3 1 2 3
// output: 2
