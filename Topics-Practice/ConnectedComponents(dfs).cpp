// Playlist video 4 (dfs) - 5:15
// Complete

/*
  n - nodes
  m - edges
  a,b - edge between node a and node b

  component numbering starts from 1.
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define csp(x) cout << x << " ";
#define fr(a,b,c) for(int a = b; a<c; a++)
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define N 100000
typedef vector<int> vi;

vi adj[N];
int result[N]={};
bool visited[N]={};
int c=0;

void dfs(int node);
void connectedComponents(int n);


int main()
{
  int n,m; cin >> n >> m;
  fr(i,0,m)
  {
    int a,b; cin >> a >> b;
    adj[a-1].pb(b-1);
    adj[b-1].pb(a-1);
  }

  connectedComponents(n);
  show1d(n,result);
}

void connectedComponents(int n)
{
  fr(i,0,n)
  {
    if(!visited[i])
    {
      c++;
      dfs(i);
    }
  }
}

void dfs(int node)
{
  visited[node]=1;
  result[node]=c;
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}
