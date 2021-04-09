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
#define M_PI_2     1.57079632679489661923a
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
#define intt int32_t
// #define int long long
// #define endl '\n'
#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}

#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a-1].pb(b-1);

class Graph
{
public:
  int n;
  vi adj[N];
  bool visited[N]={};
  vi dist;
  vi parent;
  int max_dist=-1;
  vi values;

  Graph(int fn, vvi edges, vi vals)
  {
    n=fn;
    for(auto v: edges) addEdge(v);
    for(auto x: vals) values.pb(x);
  }

  void addEdge(vi v)
  {
    adj[v[0]].pb(v[1]);
    adj[v[1]].pb(v[0]);
  }

  void clearVisited()
  {
    fr(i,0,n+1) visited[i]=0;
  }

  void bfsCalcDist(int first)
  {
    dist.resize(n+1,0);
    parent.resize(n+1,-1);
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
    vi result;
    if(start==end) {result.pb(start); return result;}

    if(dist[end]<dist[start])  swap(start,end);

    int node=end;
    if(parent[node]==-1) return result;
    while(node!=-1)
    {
      result.pb(node);
      if(node==start) break;
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

  void dfsBase()
  {
    fr(i,0,n)
    {
      if(!visited[i]) dfs(i);
    }
    clearVisited();
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
    int n,s; cin >> n >> s;
    vvi edges;
    fr(i,0,n-1)
    {
      vi v(2);
      cin >> v[0] >> v[1];
      // v[0]--; v[1]--;
      edges.pb(v);
    }
    vi vals(n+1,0); map<int,int> mpvals;
    frr(i,1,n) cin >> vals[i], mpvals[vals[i]]=i;

    vi permed(n+1,0);
    frr(i,1,n) cin >> permed[i];
    // for(auto p: mpvals) csp(p.fs),cnl(p.sn);
    Graph g(n,edges,vals);
    vi nextp(n+1,-1);
    vi partfs, partls;
    vi used(n+1,-1);
    int curr=-1;
    g.bfsCalcDist(1);
    // vshow1d(g.parent);
    frr(i,1,n)
    {
      int j = mpvals[permed[i]];
      vi path = g.findPath(i,j);
      int m = path.size();
      int st = path[0]; int end = path[m-1];
      if(used[st]!=-1)
      {
        if(used[st]==used[end]) continue;
        if(used[end]!=-1) goto wrong;
        int k=0, fl = used[st], flag=0;
        while(k<m)
        {
          int x = path[k];
          if(x==partls[fl]) flag=1;
          else if(used[x]==fl || flag) k++;
          else goto wrong;
        }
        if(flag) partls[fl] = end;
      }
      else
      {
        curr++;
        partfs.pb(st);
        fr(k,0,m-1)
        {
          used[path[k]]=curr;
          nextp[path[k]]=path[k+1];
        }
        used[end]=curr;
        partls.pb(end);
      }
    }

    correct:
      cnl(1);
      continue;

    wrong:
      cnl(0);
      continue;

  }
}
