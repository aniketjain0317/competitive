// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
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
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> bool chmin(T& a, U b){if (a > b) {a = b; return true;} return false;}
template<typename T, typename U> bool chmax(T& a, U b){if (a < b) {a = b; return true;} return false;}


#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1000000007;
const ll INF = 1000000007;
const int N = 300;

class Graph
{
public:
  int n;
  vi adj[N];
  bool visited[N]={};
  vi dist;
  vi parent;
  int max_dist=-1;
  int pref[N]={};
  int suff[N]={};
  int pref2[N]={};
  set<int> sPref;
  set<int> sSuff;

  Graph(int fn, vvi edges)
  {
    n=fn;
    for(auto v: edges) addEdge(v);
  }

  void addEdge(vi v)
  {
    adj[v[0]].pb(v[1]);
    adj[v[1]].pb(v[0]);
  }

  void clearVisited(int x=0)
  {
    fr(i,0,N) visited[i]=0;
    fr(i,0,N) pref[i]=0;
    fr(i,0,N) pref2[i]=0;
    fr(i,0,N) suff[i]=0;
  }
  //
  // void bfsCalcDist(int first)
  // {
  //   dist.resize(n,0);
  //   parent.resize(n,-1);
  //   queue<int> q;
  //   visited[first]=1;
  //   q.push(first);
  //   while(!q.empty())
  //   {
  //     int node = q.front();
  //     for(auto child: adj[node])
  //     {
  //       if(!visited[child])
  //       {
  //         dist[child]=dist[node]+1;
  //         dcount[dist[child]].pb(child);
  //         mxs(max_dist,dist[child]);
  //         parent[child]=node;
  //         visited[child]=1;
  //         q.push(child);
  //       }
  //     }
  //     q.pop();
  //   }
  // }

  // vi findPath(int start, int end)
  // {
  //   bfsCalcDist(start);
  //   vi result;
  //   int node=end;
  //   if(parent[node]==-1) return result;
  //   while(node!=-1)
  //   {
  //     result.pb(node);
  //     node=parent[node];
  //   }
  //   reverse(all(result));
  //   if(result[0]!=start) result.clear();
  //   return result;
  // }

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

  void dfs(int node, set<int> &sNode)
  {
    sPref.insert(node);
    auto it = sPref.lower_bound(node);
    pref[node] = distance(sPref.begin(), it);
    // pref2[node] = sPref.size() - pref[node] - 1;
    visited[node]=1;
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        set<int> sChild;
        dfs(child, sChild);
        // csp(node+1); csp(child+1); cnl(sChild.size());
        sChild.insert(node);
        auto it = sChild.lower_bound(node);
        suff[node] += distance(sChild.begin(), it);
        pref2[node] += sChild.size() - suff[node] - 1;
        sNode.insert(all(sChild));
      }
    }
    sNode.insert(node);
    it = sPref.lower_bound(node);
    sPref.erase(it);
  }
};

struct Modular {
  int value;
  int mod(int &v) {return (v % MOD + MOD)%MOD;}

  Modular(int v = 0) { value = mod(v);}
  Modular(int a, int b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value = value + b.value; value = mod(value); return *this;}
  Modular& operator-=(Modular const& b) {value = value - b.value; value = mod(value); return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value; value = mod(value); return *this;}

  friend Modular mexp(Modular a, int e)
  {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }

  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}

  friend Modular& operator++(Modular& a, intt) {return a += 1;}
  friend Modular operator++(Modular const& a, intt) {return Modular(a)++;}
  friend Modular& operator--(Modular& a, intt) {return a -= 1;}
  friend Modular operator--(Modular const& a, intt) {return Modular(a)--;}
};
typedef Modular mo;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  // test(t)
  {
    int n; cin >> n;
    vvi edges;
    fr(i,0,n-1)
    {
      int u,v; cin >> u >> v; u--; v--;
      edges.pb({u,v});
    }
    Graph g(n,edges);
    mo ans = 0;
    fr(i,0,n)
    {
      set<int> sSuff;
      g.dfs(i, sSuff);
      show1d(n,g.pref);
      show1d(n,g.suff);
      show1d(n,g.pref2);
      cnl("AAAAAAA");
      fr(j,0,n)
      {
        mo x = (j - g.pref[j] - g.suff[j]);
        x/=2;
        ans += x + g.su ff[j];
      }

      g.clearVisited();
    }
    ans /= n;
    cnl(ans);
  }
}
