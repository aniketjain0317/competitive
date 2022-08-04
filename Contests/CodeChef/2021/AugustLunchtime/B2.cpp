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


struct item
{
  mo val;
  mo cnt;
};

class SegTree
{
public:
  int n, m, h;
  vector<item> tree;
  vector<vector<int>> len; // [left,right)

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const mo NEUTRAL = 0;
  item merge(item& a, item& b)
  {
    item ans;
    ans.val = (a.val+b.val);
    ans.cnt = a.cnt+b.cnt;
    return ans;
  }
  item single(mo v)
  {return {v,0};}

  SegTree(int sz)
  {
    n = 1, h = 1;
    while(n<sz) h++, n<<=1; m=n<<1;

    tree.resize(m, single(NEUTRAL));
    for(int i = 0; i<sz; i++) tree[n+i] = single(NEUTRAL);
    for(int i = n-1; i; i--)  tree[i]   = merge(tree[2*i], tree[2*i+1]);

    len.resize(m, {0,n});
    for(int i = n; i<m; i++) len[i][0] = i-n,         len[i][1] = i-n+1;
    for(int i = 1; i<n; i++) len[i][0] = len[2*i][0], len[i][1] = len[2*i+1][1];
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i, mo v)
  {
    item nw; nw.val = v; nw.cnt = 1;
    tree[i+=n] = nw;
    while(i>>=1) tree[i] = merge(tree[2*i], tree[2*i+1]);
  };

  // [l,r), [lx, rx), 0-indexed
  item rec_query(int l, int r, int x=1)
  {
    int lx = len[x][0], rx = len[x][1];
    if(l<=lx && rx<=r) return tree[x];
    if(l>=rx || lx>=r) return single(NEUTRAL);

    item left = rec_query(l, r, 2*x);
    item right = rec_query(l, r, 2*x+1);
    return merge(left, right);
  }

  // [l,r)
  item query(int l, int r)
  {
    item ansLeft = single(NEUTRAL), ansRight = single(NEUTRAL);
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ansLeft = merge(ansLeft, tree[l++]);
      if(r&1) ansRight = merge(tree[--r], ansRight);
    }
    return merge(ansLeft, ansRight);
  }

  mo get(int i)
  {
    return tree[i+=n].val;
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
    vvi adj(n);
    vi p(n,0);
    fr(i,1,n)
    {
      int x; cin >> x;
      adj[x-1].pb(i);
      p[i] = x-1;
    }
    vpi arr(n);
    fr(i,0,n) cin >> arr[i].fs;
    fr(i,0,n) arr[i].sn = i;

    int f = 0;
    fr(i,0,n) if(adj[i].size()>1) f=1;
    if(!f)
    {
      mo ans = 0;
      fr(i,0,n) ans+=ans+i;
      cnl(ans);
      continue;
    }

    vvi mat(n,vi(n,0));
    vi st;
    function<void(int)> dfs = [&](int node)
    {
      for(auto x: st)
      {
        if(arr[x].fs<arr[node].fs) mat[node][x] = 1;
        else mat[x][node]=1;
      }
      st.pb(node);
      for(auto child: adj[node]) dfs(child);
      st.pop_back();
    };
    dfs(0);
    sort(all(arr));
    vector<mo> ans(n,0);
    fr(i,0,n)
    {
      int x = arr[i].sn;
      fr(y,0,n) if(mat[y][x]) ans[y]+=(ans[x]+1);
    }
    mo a = 0;
    fr(i,0,n) a+=ans[i];
    cnl(a);
  }
}
// dp[x] = sum(dp[y]+1) s.t y<x && (ny is related to nx)
