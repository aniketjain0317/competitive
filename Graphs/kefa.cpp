// Problem 580C - Codeforces
// Solved using DFS (Graphs)
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> cats;
vector<int> visited;
vector<int> catsreq;
vector <int> tree[(int)pow(10,6)];
int ans=0;

void dfs(int);

int main()
{
      cin >> n >> m;
      cats.assign(n+1,0);
      visited.assign(n+1,0);
      catsreq.assign(n+1,0);

      for(int i=1;i<=n;i++)
      {
        cin >> cats[i];
      }

      for(int i=0;i<n-1;i++)
      {
        int x,y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
      }
      if(cats[1]) catsreq[1]++;
      dfs(1);
      cout << ans << endl;
}

void dfs(int node)
{
    visited[node]=1;
    for(int child: tree[node])
    {
      if(!visited[child])
      {
        if(cats[child])
        {
          catsreq[child]=catsreq[node]+1;
        }
        if(catsreq[child] > m) continue;
        if((tree[child].size()==1)&&(visited[tree[child][0]])) ans++;
        dfs(child);
      }
    }
}
