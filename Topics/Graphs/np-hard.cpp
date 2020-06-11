// Problem 587A - Codeforces (dfs and similar / 1500)
// SOLVED ()
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> graph[n];
  for(int i=1;i<=m;i++)
  {
    int t1,t2;
    cin >> t1 >> t2;
    graph[t1-1].push_back(t2-1);
    graph[t2-1].push_back(t1-1);
  }
  queue <int> q[2];
  vector <int> final[2];
  vector<bool> visited[2];
  visited[0].assign(n,0);
  visited[1].assign(n,0);
  int flag=0;
  for(int x=0;x<n;x++)
  {
    if((!visited[0][x])&&(!visited[1][x]))
    {
      q[0].push(x);
      visited[0][x]=1;
      int r =0;
      while((!q[0].empty())||(!q[1].empty()))
      {
        if(q[r].empty()) {r=(++r)%2;}
        int node = q[r].front();
        q[r].pop();
        final[r].push_back(node);
        for(int child: graph[node])
        {
          if(visited[r][child])
          {
            flag=1; break;
          }
          int t=(r+1)%2;
          if((!visited[t][child]))
          {
            visited[t][child]=true;
            q[t].push(child);
          }
        }
        if(flag) break;
      }
    }
  }
  if(flag) cout << -1;
  else
  {
    cout << final[0].size() << endl;
    for (int node: final[0]) cout << node+1 << " ";
    cout << endl;
    cout << final[1].size() << endl;
    for (int node: final[1]) cout << node+1 << " ";
    cout << endl;
  }

}
