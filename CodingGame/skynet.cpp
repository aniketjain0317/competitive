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
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define fr(i,a,b) for(int i=a;i<b;i++)
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) forr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 1000

#define bd(a,b,adj) adj[a].pb(b); adj[b].pb(a);
#define ud(a,b,adj) adj[a].pb(b);

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;


bool visited[N]={};
vi adj [N];
vi dist(N);
vi ex(N);

void dfs(int);
void bfs(int);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,l,e;
  cin >> n >> l >> e;
  fr(i,0,l)
  {
    int n1, n2; cin >> n1 >> n2;
    adj[n1].pb(n2);
    adj[n2].pb(n1);
  }
  fr(i,0,e)
  {
    int n1;
    cin >> n1;
    ex[i]=n1;
  }

  while(1)
  {
    int sky; cin >> sky;
    int minDist=500, minNode=0;
    for(int nbr: adj[sky])
    {
      int minD1=500;
      bfs(sky);
      fr(i,0,e)
      {
        int n1 = dist[ex[i]];
        if(minD1>n1) minD1=n1;
      }
      if(minDist>minD1)
      {
        minDist=minD1;
        minNode=nbr;
      }
    }
    csp(sky);cnl(minNode);
  }
}

void dfs(int node)
{
  visited[node]=1;
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}

void bfs(int first)
{
  queue<int> q;
  visited[first]=1;
  q.push(first);
  while(!q.empty())
  {
    int node = q.front();
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        dist[child]=dist[node]+1;
        q.push(child);
        visited[child]=1;
      }
    }
    q.pop();
  }
}
