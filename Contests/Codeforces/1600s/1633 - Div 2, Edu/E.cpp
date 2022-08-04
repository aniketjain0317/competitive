// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define intt int32_t
#define int long long
#define vector deque
// #define endl '\n'

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
#define cp2(x) (__builtin_popcountll(x)==1)
#define lp2(x) (__builtin_ctzll(x))
#define tc(tno) cout << "Case #" << tno << ": "
#define dsp(x) cout << #x << ": " << x << ", "
#define dnl(x) cout << #x << ": " << x << endl


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




typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1000000007;
const ll INF = 1LL<<62;
const int N = 100005;

class DisjSet
{
public:
  int n;
  vector<int> parent;
  vector<int> sz;

  DisjSet(int m)
  {
    n=m;
    parent.resize(n,0);
    sz.resize(n,1);
    for(int i =0; i<n; i++) parent[i]=i;
  }

  int find(int x)
  {
    if(parent[x]!=x) parent[x] = find(parent[x]);
    return parent[x];
  }

  int merge(int u, int v)
  {
    int x = find(u), y = find(v);
    if(x==y) return 0;
    if(sz[x]<sz[y]) swap(x,y);
    parent[y] = x;
    sz[x]+=sz[y];
    return 1;
  }
};

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m; cin >> n >> m;
  vvi edges(m,vi(3));
  for(auto &edge: edges) cin >> edge[1] >> edge[2] >> edge[0];
  int p,k,a,b,c; cin >> p >> k >> a >> b >> c;
  vi queries(k);
  int mst = 0;
  fr(i,0,p) cin >> queries[i];
  fr(i,p,k) queries[i] = (a*queries[i-1]+b)%c;
  sort(all(queries));
  sort(all(edges));
  vvi flipped, unflipped(edges);
  int ans = 0;
  fr(q,0,k)
  {
    int x = queries[q]; if(q) x-=queries[q-1];
    if(q && !x) {mst^=ans; continue;}
    while(!unflipped.empty() && unflipped[0][0]<x)
    {
      unflipped[0][0] = -unflipped[0][0];
      flipped.push_front(unflipped[0]);
      unflipped.pop_front();
    }
    for(auto &edge: flipped) edge[0]+=x;
    for(auto &edge: unflipped) edge[0]-=x;
    // dsp(flipped); dnl(unflipped);
    int nn = flipped.size(), mm = unflipped.size();
    int i = 0, j = 0;
    ans = 0;
    DisjSet dsu(n+1);
    while(i<nn && j<mm)
    {
      vi edge = unflipped[j];
      if(chmin(edge, flipped[i])) i++;
      else j++;
      if(dsu.merge(edge[1], edge[2])) ans+=edge[0];
    }
    while(i<nn)
    {
      vi edge = flipped[i++];
      if(dsu.merge(edge[1], edge[2])) ans+=edge[0];
    }
    while(j<mm)
    {
      vi edge = unflipped[j++];
      if(dsu.merge(edge[1], edge[2])) ans+=edge[0];
    }
    mst^=ans;
  }
  cnl(mst);
}
// 5 8
// 4 1 4
// 3 1 0
// 3 5 3
// 2 5 4
// 3 4 8
// 4 3 4
// 4 2 8
// 5 3 9
// 3 11 1 1 13
// 1 2 3
