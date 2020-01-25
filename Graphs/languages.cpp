//Problem 277A - Codeforces (dfs and similar / 1500)
//Unsolved (WA on T4)
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int>graph[500];
int visited[500]={};
int isolated=0;
int sc=0;
void dfs(int node);

int main()
{
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    int t;
    cin >> t;
    if(!t) isolated++;
    for(int j=0;j<t;j++)
    {
      int l;
      cin >> l;
      graph[i].push_back(100+l);
      graph[100+l].push_back(i);
    }
  }

  for(int k=101;k<=100+m;k++)
  {
    if(graph[k].size() && !visited[k])
    {
      sc++;
      dfs(k);
    }
  }
  int ans = (sc -1) + (isolated);
  cout << ans;
}

void dfs(int node)
{
  visited[node]=1;
  for(int child: graph[node])
  {
    if (!visited[child])
    {
      dfs(child);
    }
  }
}
