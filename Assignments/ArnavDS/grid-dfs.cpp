#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int m,n,last;
vi adj[100000];
int visited[100000]={};
deque<int> path;
int flag=0;

void dfs(int node);
int main()
{
  cin >> m >> n;
  last = m*n;
  for(int i =0; i<last; i++)
  {
    int x; cin >> x;
    bool b;
    cin >> b;
    if(b) adj[x].push_back(x-n);
    cin >> b;
    if(b) adj[x].push_back(x+1);
    cin >> b;
    if(b) adj[x].push_back(x+n);
    cin >> b;
    if(b) adj[x].push_back(x-1);
  }
  dfs(1);
  for(auto x: path) cout << x << " ";
  cout << endl;
}

void dfs(int node)
{
  path.push_back(node);
  visited[node]=1;
  if(node==last) {flag=1; return;}
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      dfs(child);
      if(flag) return;
    }
  }

  path.pop_back();
}
