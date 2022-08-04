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
const int N = 100005;

struct item
{
  int val;
};

struct SegTree
{
  int n;
  int h;
  int size;
  vector<item> tree;
  vector<pi> len;

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = INF;
  item merge(item& a, item& b)
  {
    item ans;
    ans.val = min(a.val, b.val);
    return ans;
  }

  item single(int v)
  {
    return {v};
  }

  void init(int sz, vi &arr)
  {
    n = sz;
    h = ceil(log2(n))+1;
    size = 1LL<<(h-1);

    tree.resize(2*size, single(NEUTRAL));
    fr(i,0,n) tree[n+i] = single(arr[i]);
    frrb(i,n-1,0) tree[i] = merge(tree[2*i], tree[2*i+1]);

    // length = 1<<(h-floor(log2(x)))
    // left = (x - 1<<floor(log2(x))) * length
    // right = left + length
    len.resize(2*size, {0,size});
    fr(x,1,size)
    {
      int l = len[x].fs, r = len[x].sn;
      int m = (l+r)/2;
      len[2*x]={l,m};
      len[2*x+1]={m,r};
    }
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i, int v)
  {
    int x = size + i;
    tree[x] = single(v);
    while(x>>=1)
      tree[x] = merge(tree[2*x], tree[2*x+1]);
  }

  // [l,r), [lx, rx), 0-indexed
  item query(int l, int r, int x=1)
  {
    int lx = len[x].fs, rx = len[x].sn;
    if(lx>=l && rx<=r) return tree[x];
    if(rx<=l || lx>=r) return single(NEUTRAL);
    item left = query(l, r, 2*x);
    item right = query(l, r, 2*x+1);
    return merge(left, right);
  }

  // [l,r)
  item iterative_query(int l, int r)
  {
    item ans = single(NEUTRAL);
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1)
    {
      if(l&1) ans = merge(ans, tree[l++]); // if l is odd: right one
      if(r&1) ans = merge(ans, tree[--r]); // if (r-1) is even: left one
    }
    return ans;
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
    int n,q; cin >> n >> q;
    vector<int> A(n); cin >> A;
    vpi query(q); cin >> query;

    vi arr(n,INF);
    fr(i,0,n-1) arr[i] = abs(A[i+1]-A[i]);
    SegTree st;
    st.init(n,arr);

    fr(i,0,q)
    {
      int x = query[i].fs-1;
      A[x] = query[i].sn;
      if(x) st.update(x-1, llabs(A[x]-A[x-1]));
      if(x<(n-1)) st.update(x, llabs(A[x+1]-A[x]));
      cnl(st.query(0,n).val);
    }
  }
}

// n/2 cheapest connect to the other half
// 1 2 3 4 5 6 7
//
