// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 200000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define bd(a,b,adj) adj[a].pb(b); adj[b].pb(a);
#define ud(a,b,adj) adj[a].pb(b);



bool visited[N]={};
vi adj[N];
int dist[N];
int x=-1;
vi nets;
vector<vpi> redundant;

void dfs(int,int,int);
void bfs(int);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test(t)
  {
    int n,m; cin >> n >> m;
    fr(i,0,m)
    {
      int a,b;
      cin >> a >> b;
      bd(a-1,b-1,adj);
    }
    fr(i,0,n)
    {
      if(!visited[i])
      {
        x++;
        nets.pb(0);
        vpi empty;
        redundant.pb(empty);
        dfs(i,i,0);
      }
    }
    cnl("A"<<x);
    show1d(x+1,nets);
    for(auto a: redundant)
    {
      for(auto p: a)
      {csp("("<<p.fs<<","<<p.sn<<")");}
      cout << endl;
    }
  }
}


void dfs(int node, int parent, int c)
{
  visited[node]=1;
  int sz = adj[node].size();
  int check[N]={};
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      dfs(child,node,0);
      check[child]++;
    }
    else
    {
      if(child==parent) {continue;}
      // if(!check[child]) {check[child]++; continue;}
      nets[x]++;
      pi p; p.fs = node; p.sn = child;
      redundant[x].pb(p);
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
