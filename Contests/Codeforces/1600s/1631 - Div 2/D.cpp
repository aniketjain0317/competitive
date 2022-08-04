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

class SegTree
{
public:
  int n;
  int h;
  int cap;
  vi tree;
  const int NEUTRAL = 0;

  int op(int& a, int& b)
  {
    return a+b;
  }

  SegTree(int sz, vi arr)
  {
    n = sz;
    h = ceil(log2(n))+1;
    cap = 1LL<<h;

    tree.resize(cap,NEUTRAL);
    for(int i = 0; i<n; i++)
      update(i, arr[i]);
  }

  // pos is 0-indexed
  void update(int pos, int val)
  {
    int curr = cap/2 + pos;
    tree[curr] = val;
    curr>>=1;
    while(curr)
    {
      tree[curr] = op(tree[2*curr], tree[2*curr+1]);
      curr>>=1;
    }
  }


  // [l,r) are 0 indexed;
  int query(int l, int r)
  {
    return _dfs(1, 0, cap/2, l, r);
  }

  // [l,r)
  // [lx, rx)
  int _dfs(int x, int lx, int rx, int l, int r)
  {
    if(lx>=l && rx<=r) return tree[x];
    if(rx<=l || lx>=r) return NEUTRAL;

    int mx = (lx + rx)/2;
    int left = _dfs(2*x, lx, mx, l, r);
    int right = _dfs(2*x+1, mx, rx, l, r);
    return op(left, right);
  }

  void printTree()
  {
    cnl("TREEEEEEEEE: ");
    frr(k,1,h)
    {
      fr(i,1<<(k-1), 1<<k)
        csp(tree[i]);
      cout << endl;
    }
    cout << endl;
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
    int n,k; cin >> n >> k;
    vi arr(n); cin >> arr;
    vi cnt(n+1,0);
    fr(i,0,n) cnt[arr[i]]++;
    SegTree st(n+1, cnt);
    auto check = [&](int x, int y)
    {
      int a = st.query(x,y);
      // dsp(a); dsp(x); dnl(y);
      if((2*a-n)>=k) return true;
      else return false;
    };
    int ans = INF;
    int a = 1, b = n;
    frr(x,0,n)
    {
      int y = x;
      for(int l = 1LL<<32; l; l>>=1)
      {
        while((y+l)<=(n+1) && !check(x,y+l)) y+=l;
      }
      if(!check(x,y+1)) continue;
      if(chmin(ans, y-x)) a=x,b=y;
    }
    vpi v;
    int q = st.query(a,b+1), p = n-q, curr = 0, ls = 0;
    fr(i,0,n)
    {
      int x = arr[i];
      // dsp(i); dsp(p); dnl(q);
      if((q-p)==1) {v.pb({ls+1,n}); break;}
      if(x>=a && x<=b) curr++, q--;
      else curr--, p--;
      if(curr==1)
      {
        v.pb({ls+1, i+1});
        ls = i+1;
        curr=0;
      }
    }
    while(v.size()>k)
    {
      pi aa = v.back(); v.pop_back();
      pi bb = v.back(); v.pop_back();
      v.push_back({bb.fs, aa.sn});
    }
    // csp("AAAAAAAA");
    csp(a); cnl(b);
    cnl(v);
  }
}
