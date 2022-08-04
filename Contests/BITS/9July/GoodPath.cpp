#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<vector<int>> adj;
vector<int> values;
vector<int> parent;
vector<int> path;
map<int,int> freq;

bool checkGood()
{
  int m = path.size();
  for(int i = 0; i<60; i++)
  {
    int value = path[rand()%m];
    if(freq[value] >= ceil(m/2.0)) return true;
  }
  return false;
}

void dfs(int node)
{
  int value = values[node];
  path.push_back(value);
  freq[value]++;
  if(checkGood()) ans++;
  for(auto &child: adj[node]) if(parent[node]!=child)
  {
    parent[child] = node;
    dfs(child);
  }
  path.pop_back();
  freq[value]--;
}

void solve()
{
  srand(time(0));
  cin >> n; ans = 0;
  adj.clear(); parent.clear();
  path.clear(); freq.clear();
  adj.resize(n); parent.resize(n,0);
  for(int i = 0; i<n; i++)
  {
    int x; cin >> x;
    values.push_back(x);
  }
  for(int i = 0; i<(n-1); i++)
  {
    int u,v; cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int t; cin >> t;
  while(t--) solve();
}
