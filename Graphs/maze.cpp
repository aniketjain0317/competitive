//Problem 377A - Codeforces (dfs and similar / 1600)
//TLE on Test 8 (See maze2.cpp / Solved)

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,k;
  cin >> n >> m >> k;
  int map[n][m]={};
  vector<pair<int,int>> adj[n][m];
  vector <pair<int,int>> edges[4];

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      char t;
      cin >> t;
      if(t=='.') map[i][j]=1;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if (map[i][j])
      {
        int c=0;
        if(i&&map[i-1][j]) {adj[i][j].push_back(make_pair(i-1,j)); c++;}
        if(j&&map[i][j-1]) {adj[i][j].push_back(make_pair(i,j-1)); c++;}
        if(j<m-1&&map[i][j+1]) {adj[i][j].push_back(make_pair(i,j+1)); c++;}
        if(i<n-1&&map[i+1][j]) {adj[i][j].push_back(make_pair(i+1,j)); c++;}
        edges[c-1].push_back(make_pair(i,j));
      }
    }
  }

  while(k--)
  {
    int flag=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if (adj[i][j].size()==1)
        {
          for(auto x: adj[i][j])
          {
            adj[x.first][x.second].erase(adj[x.first][x.second].begin());
          }
          adj[i][j].clear();
          map[i][j]=2;
          flag=1;
          break;
        }
      }
      if(flag) break;
    }
    if(!flag)
    {
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if (adj[i][j].size())
          {
            for(auto x: adj[i][j])
            {
              adj[x.first][x.second].erase(adj[x.first][x.second].begin());
            }
            adj[i][j].clear();
            map[i][j]=2;
            flag=1;
            break;
          }
        }
        if(flag) break;
      }
    }
  }
  cout << endl << endl << endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(map[i][j]==0) cout << '#';
      if(map[i][j]==1) cout << '.';
      if(map[i][j]==2) cout << 'X';
    }
    cout << endl;
  }

  // another method - but could not complete it:


  // while(k--)
  // {
  //   int x=0;
  //   pair <int,int> val;
  //   while(true)
  //   {
  //     if(edges[x].size())
  //     {
  //       val = edges[x].back();
  //       edges[x].pop_back();
  //       break;
  //     }
  //     x++;
  //   }
  //   for(int i=x+1;i<4;i++)
  //   {
  //     if(binary_search(edges[i].begin(),edges[i].end(),make_pair(val.first + 1, val.second)))
  //     {
  //       pair <int,int> sec = make_pair(val.first + 1,val.second);
  //       auto it = lower_bound(edges[i].begin(),edges[i].end(),make_pair(val.first + 1, val.second));
  //       edges[i].erase(iter);
  //       edges[i-1].push_back(sec);
  //     }
  //     if(find(edges[i].begin(),edges[i].end(),make_pair(val.first - 1, val.second)))
  //     {
  //       pair <int,int> sec = make_pair(val.first - 1,val.second);
  //       edges[i].erase(sec);
  //       edges[i-1].push_back(sec);
  //     }
  //     if(find(edges[i].begin(),edges[i].end(),make_pair(val.first, val.second+1)))
  //     {
  //       pair <int,int> sec = make_pair(val.first + 1,val.second+1);
  //       edges[i].erase(sec);
  //       edges[i-1].push_back(sec);
  //     }
  //     if(find(edges[i].begin(),edges[i].end(),make_pair(val.first, val.second-1)))
  //     {
  //       pair <int,int> sec = make_pair(val.first,val.second-1);
  //       edges[i].erase(sec);
  //       edges[i-1].push_back(sec);
  //     }
  //   }
  // }
}
