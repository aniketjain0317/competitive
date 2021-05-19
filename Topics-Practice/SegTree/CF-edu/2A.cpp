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
#define intt int32_t
#define int long long
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

// Range Queries, Point Update
// updates/queries: 0 indexed, storage array: 1 indexed
// REMEMBER TO CHANGE neutral AND op BOTH, ALONG WITH update (and print)

struct item
{
  int val, pref, suff, sum;
};

// Range Query, Point Update
struct SegTree
{
  int n;
  int h;
  int size;
  vector<item> tree;

  // CHANGE NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  item merge(item a, item b)
  {
    item ans;
    ans.sum = a.sum+b.sum;
    ans.val = max(a.suff + b.pref, max(a.val, b.val));
    ans.pref = max(a.pref, a.sum + b.pref);
    ans.suff = max(b.suff, b.sum + a.suff);
    return ans;
  }

  item single(int v)
  {
    return {max(v,0LL), max(v,0LL), max(v,0LL), v};
  }

  void init(int sz, int arr[])
  {
    n = sz;
    h = ceil(log2(n))+1;
    size = 1LL<<(h-1);

    tree.resize(2*size, single(NEUTRAL));
    fr(i,0,n) update(i, arr[i]);
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i, int v)
  {
    int x = size + i;
    tree[x] = single(v);
    while(x>>=1)
      tree[x] = merge(tree[2*x], tree[2*x+1]);
  }

  // [l,r)
  // [lx, rx)
  item query(int l, int r, int x, int lx, int rx)
  {
    if(lx>=l && rx<=r) return tree[x];
    if(rx<=l || lx>=r) return single(NEUTRAL);
    int mx = (lx + rx)/2;
    item left = query(l, r, 2*x, lx, mx);
    item right = query(l, r, 2*x+1, mx, rx);
    return merge(left, right);
  }

  // [l,r) are 0 indexed;
  item query(int l, int r)
  {
    return query(l, r, 1, 0, size);
  }

  void printTree()
  {
    cnl("TREEEEEEEEE: ");
    frr(k,1,h)
    {
      fr(i,1<<(k-1), 1<<k)
// CHANGE THIS IF ITEM.V CANNOT BE PRINTED
        csp(tree[i].val);
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
  int n, m; cin >> n >> m;
  int arr[n]; cinp(n,arr);
  SegTree st; st.init(n,arr);
  cnl(st.query(0,n).val);
  fr(i,0,m)
  {
    int a, b; cin >> a >> b;
    st.update(a,b);
    cnl(st.query(0,n).val);
  }
}
