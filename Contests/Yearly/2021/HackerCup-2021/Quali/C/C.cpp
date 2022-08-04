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
#define cp2(x) (__builtin_popcountll(x)==1)
#define lp2(x) (__builtin_ctzll(x))
#define tc(tno) cout << "Case #" << tno << ": "


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
const ll INF = 1LL<<62;
const int N = 100005;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("myans.txt","w",stdout);
  freopen("input.txt","r",stdin);
  test(t)
  {
    int n,k; cin >> n; k = 1;
    vi cost(n,0); cin >> cost;
    vector<set<int>> adj(n);
    fr(i,0,n-1)
    {
      int u,v; cin >> u >> v; u--,v--;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    if(!k)
    {
      tc(tno);
      cnl(cost[0]);
      continue;
    }

    function<vi(int,int,int)> findMax = [&](int node, int parent, int sm) -> vi
    {
      sm+=cost[node];
      vi mx({sm,node});
      for(auto child: adj[node]) if(child!=parent)
        chmax(mx,findMax(child, node, sm));
      return mx;
    };
    function<bool(int,int,int)> delPath = [&](int node, int parent, int end) -> bool
    {
      if(node==end)
      {
        cost[node]=0;
        if(node!=parent)
        {
          adj[node].erase(parent);
          adj[parent].erase(node);
        }
        return true;
      }
      for(auto child: adj[node]) if(child!=parent)
      {
        if(delPath(child,node, end))
        {
          cost[node]=0;
          if(node!=parent) adj[node].erase(parent), adj[parent].erase(node);
          return true;
        }
      }
      return false;
    };

    int ans = 0;
    // 1st run
    vi a1 = findMax(0,0,0);
    ans += a1[0];
    delPath(0,0,a1[1]);

    // k-1 runs
    fr(i,0,k-1)
    {
      vi mx(3,0);
      fr(j,0,n)
      {
        vi a = findMax(j,j,0); a.pb(j);
        chmax(mx,a);
      }
      ans+=mx[0];
      delPath(mx[1], mx[1], mx[2]);
    }

    // last run
    vi a2 = findMax(0,0,0);
    ans += a2[0];
    tc(tno);
    cnl(ans);
  }
}
