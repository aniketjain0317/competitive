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
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 10005;


class Graph
{
public:
  int n;
  vi adj[N];
  bool visited[N]={};
  vi dist;
  vi parent;
  int max_dist=-1;
  int val[N]={};
  int que[N]={};
  int curr=-1;
  int f=-1;
  deque<pi> del;
  vpi join;

  Graph(int fn, vvi &edges)
  {
    n=fn;
    for(auto &v: edges) addEdge(v);
  }

  void addEdge(vi &v)
  {
    adj[v[0]].pb(v[1]);
    adj[v[1]].pb(v[0]);
  }

  void clearVisited()
  {
    frr(i,0,n) visited[i]=0;
  }

  void bfsCalcDist(int first)
  {
    dist.resize(n,0);
    parent.resize(n,-1);
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
          mxs(max_dist,dist[child]);
          parent[child]=node;
          visited[child]=1;
          q.push(child);
        }
      }
      q.pop();
    }
    clearVisited();
  }

  vi findPath(int start, int end)
  {
    bfsCalcDist(start);
    vi result;
    int node=end;
    if(parent[node]==-1) return result;
    while(node!=-1)
    {
      result.pb(node);
      node=parent[node];
    }
    reverse(all(result));
    if(result[0]!=start) result.clear();
    return result;
  }

  void bfs(int first)
  {
    queue<int> q;
    visited[first]=1;
    q.push(first);
    while(!q.empty())
    {
      auto node = q.front();
      for(auto child: adj[node])
      {
        if(!visited[child])
        {
          q.push(child);
          visited[child]=1;
        }
      }
      q.pop();
    }
  }

  void dfsCalcVal(int node)
  {
    visited[node]=1;
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        dfs(child);
      }
    }

    for(auto &child:adj[node]) mxs(val[node], val[child]+1);
  }

  void dfs(int node)
  {
    visited[node]=1;
    vpi v;
    for(auto &child: adj[node]) v.pb({val[child], child});
    sort(all(v), greater<pi>());
    for(int i = 1+que[node]; i<(int)v.size(); i++) del.pb({v[i].sn, node}), que[v[i].sn]=1;

    for(auto &child: adj[node])
    {
      if(!visited[child] && !que[child])
      {
        dfs(child);
      }
    }

    if(adj[node].empty())
    {
      if(f==1) {join.pb({curr, node});  f--;}
      else f++;
      curr = node;
    }
  }


  void dfsBase()
  {
    dfs(1);
    while(!del.empty())
    {
      auto p = del.front();
      dfs(p.sn);
      del.pop_front();
    }
  }
};


intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n; cin >> n;
    vvi edges;
    fr(i,0,n-1)
    {
      int a,b;
      cin >> a >> b;
      edges.pb({a,b});
    }
    Graph g(n,edges);
    cnl("A");
    g.dfsCalcVal(1);
    csp("A");
    g.clearVisited();
    g.dfsBase();
    cnl(g.join.size());
    cnl(g.del.size());
  }
}
