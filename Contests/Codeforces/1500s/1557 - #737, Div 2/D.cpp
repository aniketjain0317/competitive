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
const ll INF = 1LL<<60;
const int sz = 100000;

struct segtree {
   int n, h;
   vector<int> tree, ex;
   const static int inf = INT_MAX;
// 0 - indexed, all method calls for [l, r) range

   void renew(int nn) {
      n = nn, h = 32 - __builtin_clz(n);
      tree.resize(n<<1,0); ex.resize(n,0);
      for(int i=0; i<n; i++) tree[n+i] = tree[i], ex[i] = 0;
      for(int i=n-1; i>=0; i--) tree[i] = max(tree[i<<1], tree[i<<1|1]);
   }

   inline void apply(int p, int v) {
      mxs(tree[p], v);
      if(p < n) mxs(ex[p], v);
   }

   inline void pull(int p) {
      while(p > 1)
         p >>= 1, tree[p] = max(max(tree[p<<1], tree[p<<1|1]) , ex[p]);
   }

   void push(int p) {
      for(int s=h; s; s--) {
         int i = p >> s;
         if(ex[i]) {
            apply(i<<1, ex[i]);
            apply(i<<1|1, ex[i]);
            ex[i] = 0;
         }
      }
   }

   void update(int l, int r, int v) {
      l += n, r += n;
      int l0 = l, r0 = r;
      while(l < r) {
         if(l&1) apply(l++, v);
         if(r&1) apply(--r, v);
         l >>= 1, r >>= 1;
      }
      pull(l0), pull(r0 - 1);
   }

   int query(int l, int r) {
      l += n, r += n;
      push(l), push(r - 1);   // only for update trees
      int res = 0;
      while(l < r) {
         if(l&1) res = max(res, tree[l++]);
         if(r&1) res = max(tree[--r], res);
         l >>= 1, r >>= 1;
      }
      return res;
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
  vvi intervals;
  set<int> s;
  fr(i,0,m)
  {
    int x,l,r; cin >> x >> l >> r;
    s.insert(l);
    s.insert(r);
    intervals.pb({x,l,r+1});
  }
  int curr = 1;
  map<int,int> idx;
  vector<vvi> r(n+1);
  for(auto x: s) idx[x] = curr++;
  fr(i,0,m) frr(j,1,2) intervals[i][j] = idx[intervals[i][j]];
  fr(i,0,m) r[intervals[i][0]].push_back(intervals[i]);

  segtree st; st.renew(idx.size()+5);
  int ans = 0;
  fr(i,0,n)
  {
    int mx = 0;
    for(auto v: r[i])
      mxs(mx,st.query(v[1], v[2]));
    mx++;
    for(auto v: r[i]) st.update(v[1], v[2], mx);
    mxs(ans,mx);
  }
  cnl(ans);
}
