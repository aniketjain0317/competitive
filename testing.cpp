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

// Range Queries, Point Update
// updates/queries: 0 indexed, storage array: 1 indexed
class SegTree
{
public:
  int n, m, h;
  vector<vector<int>> tree;
  vector<vector<int>> len; // [left,right)

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  vector<int> merge(vector<int>& a, vector<int>& b)
  {
    vector<int> ans;
    ans[0] = a[0]+b[0];
    return ans;
  }
  item single(int v)
  {return {v};}

  SegTree(int sz, vector<int> arr)
  {
    n = 1, h = 1;
    while(n<sz) h++, n<<=1; m=n<<1;

    tree.resize(m, single(NEUTRAL));
    for(int i = 0; i<sz; i++) tree[n+i] = single(arr[i]);
    for(int i = n-1; i; i--)  tree[i] = merge(tree[2*i], tree[2*i+1]);

    len.resize(m, {0,n});
    for(int i = n; i<m; i++) len[i][0] = len[i][1] = i;
    for(int i = 1; i<n; i++) len[i][0] = len[2*i][0], len[i][1] = len[2*i+1][1];
  }



  // i is 0-indexed, tree is 1-indexed
  void update(int i, int v)
  {
    tree[i+=n] = single(v);
    while(i>>=1)
      tree[i] = merge(tree[2*i], tree[2*i+1]);
  }

  // [l,r), [lx, rx), 0-indexed
  vector<int> rec_query(int l, int r, int x=1)
  {
    int lx = len[x][0], rx = len[x][1];
    if(l<=lx && rx<=r) return tree[x];
    if(l>=rx || lx>=r) return single(NEUTRAL);

    vector<int> left = rec_query(l, r, 2*x);
    vector<int> right = rec_query(l, r, 2*x+1);
    return merge(left, right);
  }

  // [l,r)
  vector<int> query(int l, int r)
  {
    vector<int> ansLeft = single(NEUTRAL), ansRight = single(NEUTRAL);
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ansLeft = merge(ansLeft, tree[l++]);
      if(r&1) ansRight = merge(tree[--r], ansRight);
    }
    return merge(ansLeft, ansRight);
  }

  void printTree();
  int find(int k, int x = 1)
  {
    // int lx = len[x][0], rx = len[x][1];
    if(tree[x][0]<k) return -1;
    if(x>=n) return x-n;

    int ans = find(k,2*x);
    if(ans==-1) ans = find(k-tree[2*x][0],2*x+1);
    return ans;
  }
};


int MAXN = 100000;
intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
}
