//Problem 277A - Codeforces (dfs and similar / 1500)
//Solved (optimized the solution)
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> graph[500];
vector <int> langs[500];
int visited[500]={};
int notEmpty[500]={};
int iso=0,cnt=0;
void dfs(int);
int main()
{
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    int t;
    cin >> t;
    int arr[t];
    if(!t) iso++;
    for(int i=0;i<t;i++)
    {
      int l;
      cin >> l, l--;
      arr[i]=l;
      if(i){langs[l].push_back(arr[i-1]);
      langs[arr[i-1]].push_back(l);}
    }


  }

  for(int i=0;i<m;i++)
  {
    if(langs[i].size()&&!visited[i])
    {
      dfs(i);
      cnt++;
    }
  }

  if(cnt) cout << cnt+iso-1;
  else cout << iso;
}

void dfs(int node)
{
  visited[node]=1;
  for(int child: langs[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}
