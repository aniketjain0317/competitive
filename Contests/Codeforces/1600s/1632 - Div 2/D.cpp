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

struct item
{
  int val;
};

class SegTree
{
public:
  int n,m;
  vector<item> tree;
  const int NEUTRAL = 0;
  item single(int x)
  {return {x};}
  item merge(item a, item b)
  {return {__gcd(a.val,b.val)};}

  SegTree(int len, vector<int> &arr)
  {
    n = 1;
    while(n<len) n<<=1; m=n<<1;
    tree.resize(m,single(NEUTRAL));
    for(int i = 0; i<len; i++) tree[n+i]=single(arr[i]);
    for(int i = n-1; i>=0; i--) tree[i]=merge(tree[2*i], tree[2*i+1]);
  }

  void update(int i, int val)
  {
    tree[i+=n]=single(val);
    for(i>>=1; i; i>>=1) tree[i]=merge(tree[2*i], tree[2*i+1]);
  }

  item query(int l, int r)
  {
    item ans = single(NEUTRAL);
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ans = merge(ans,tree[l++]);
      if(r&1) ans = merge(ans,tree[--r]);
    }
    return ans;
  }
};


void solve()
{
  int n; cin >> n;
  vi arr(n); cin >> arr;
  SegTree st(n,arr);
  int ls = 0, prev = 0;
  vi ans(n);
  fr(i,0,n)
  {
    int lf = i;
    for(int l = 1LL<<32; l; l>>=1)
    {
      // CHECK: if GCD>=len
      while((lf-l)>=ls && st.query(lf-l, i+1).val>=(i-(lf-l)+1)) lf-=l;
    }
    // dsp(ls); dsp(lf), dsp(i), dnl(st.query(lf, i+1).val);
    if(st.query(lf, i+1).val==(i-lf+1)) ans[i]=++prev, ls = (i+1);
    else ans[i]=prev;
  }
  cnl(ans);
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  // test(t)
  {
    solve();
  }
}
