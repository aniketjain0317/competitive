// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define nl cout << endl
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) forr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

vector<int>graph[2000];
vector<int>dist;
vector<int>visited;
int flag=0;


void bfs(int);
int main()
{
  int t;cin >> t;
  int ans[t]={};
  fr(sc,0,t)
  {
    int n,m; cin >> n >> m;
    dist.assign(n,0);
    visited.assign(n,0);
    fr(i,0,n) graph[i].clear();
    flag=0;
    fr(i,0,m)
    {
      int t1,t2; cin >> t1 >> t2;
      graph[t1].pb(t2);
      graph[t2].pb(t1);
    }

    fr(i,0,n)
    {
      if(!visited[i]) bfs(i);
      if(flag) break;
    }
    if(flag) ans[sc]=1;
    else ans[sc]=0;
  }
  fr(sc,0,t)
  {
    cout << "Scenario #" << sc+1 << ":\n";
    if(ans[sc]) cout << "Suspicious bugs found!\n";
    else cout << "No suspicious bugs found!\n";
  }
}

void bfs(int s)
{
  queue <int> q;
  q.push(s);
  visited[s]=1;
  dist[s]=0;
  while(!q.empty())
  {
    int node = q.front();
    q.pop();
    for(int child: graph[node])
    {
      if(!visited[child])
      {
        q.push(child);
        dist[child]=dist[node]+1;
        visited[child]=1+(dist[child]%2);
      }
      else if(visited[child]==visited[node]) {flag=1;return;}
    }
  }
}
