// Problem
//

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


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
#define endl '\n'
#define intt int32_t
// #define int long long

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

class WeightedGraph
{
public:
  int n;
  vvi adj[N];
  bool visited[N]={};
  vi dist;
  vi parent;

  WeightedGraph(int fn, vvi edges)
  {
    n=fn;
    for(auto v: edges) addEdge(v);
  }

  void addEdge(vi v)
  {
    adj[v[1]].pb({v[0],v[2]});
    adj[v[2]].pb({v[0],v[1]});
  }

  void clearVisited()
  {
    fr(i,0,N) visited[i]=0;
  }

  void djikstra(int s)
  {
    dist.resize(n,INF);
    dist[s]=0;
    priority_queue<vi,vvi, greater<vi>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
      auto tp = pq.top();
      int node = tp[1];
      pq.pop();
      for(auto edge: adj[node])
      {
        auto child = edge[1];
        int new_val = dist[node]+edge[0];
        if(new_val<dist[child])
        {
          dist[child]=new_val;
          pq.push({dist[child], child});
        }
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
      auto node = q.front();
      for(auto edge: adj[node])
      {
        auto child=edge[1];
        if(!visited[child])
        {
          q.push(child);
          visited[child]=1;
        }
      }
      q.pop();
    }
    clearVisited();
  }

  void dfs(int node)
  {
    visited[node]=1;
    for(auto edge: adj[node])
    {
      auto child = edge[1];
      if(!visited[child])
      {
        dfs(child);
      }
    }
  }

  void dfsBase()
  {
    fr(i,0,n)
    {
      if(!visited[i]) dfs(i);
    }
    clearVisited();
  }
};

void djikstra(int s);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m; cin >> n >> m;
  vvi edges;
  fr(i,0,m)
  {
    int a,b,c; cin >> a >> b >> c;
    edges.pb({c,a-1,b-1});
  }
  int s; cin >> s; s--;

  WeightedGraph wg(n,edges);
  vi dist = wg.djikstra(s);
  vshow1d(dist);
}
//
// void djikstra(int s)
// {
//    priority_queue<pi,vpi,greater<pi>> pq;
//    pq.push(mp(0,s));
//    dist[s]=0;
//    while(!pq.empty())
//    {
//      pi node=pq.top();
//      pq.pop();
//      for(auto child: adj[node.sn])
//      {
//        int v=child.sn;
//        int nwt = dist[node.sn]+child.fs;
//        if(dist[v]>nwt)
//        {
//          dist[v]=nwt;
//          pq.push(mp(dist[v],v));
//        }
//      }
//    }
// }
