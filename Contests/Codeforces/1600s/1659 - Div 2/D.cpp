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
#define cnlret(x) {cnl(x); return;}


template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T>             ostream& operator<<(ostream& os,  set<T>  v)   {os<<"{"; for (auto& i : v) os << i << ','; os<<"}"; return os;}
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

// struct item
// {
//   int val;
//   friend ostream& operator<<(ostream& os, const item& x) {os << x.val; return os;}
// };
//
// class SegTree
// {
// public:
//   int n, m, h;
//   vector<item> tree;
//   vector<vector<int>> len; // [left,right)
//
//   // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
//   const int NEUTRAL = 0;
//
//   // OP is left to right.
//   // i.e. v comes later and is merged into tree[x];
//   void merge(int x, item& v)
//   {
//
//     item ans;
//     ans.val = (tree[x].val+v.val);
//     tree[x] = ans;
//   }
//
//   item single(int v)
//   {return {v};}
//
//   SegTree(int sz, vector<int> arr)
//   {
//     n = 1, h = 1;
//     while(n<sz) h++, n<<=1; m=n<<1;
//
//     tree.resize(m, single(NEUTRAL));
//     marked.resize(m,0);
//     for(int i = 0; i<sz; i++) tree[n+i] = single(arr[i]);
//     // for(int i = n-1; i; i--)  tree[i]   = merge(tree[2*i], tree[2*i+1]);
//
//     len.resize(m, {0,n});
//     for(int i = n; i<m; i++)   len[i][0] = i-n,         len[i][1] = i-n+1;
//     for(int i = n-1; i>0; i--) len[i][0] = len[2*i][0], len[i][1] = len[2*i+1][1];
//   }
//
//   void push(int x)
//   {
//     if (marked[x] && x<n) {
//         merge(2*x, tree[x]);
//         merge(2*x+1, tree[x]);
//         marked[x] = false;
//     }
//   }
//
//   item query(int i, int x = 1)
//   {
//     int lx = len[x][0], rx = len[x][1];
//     if((rx-lx)==1)      return tree[x];
//     push(x);
//     if(i < len[2*x][1]) return query(i, 2*x);
//     else                return query(i, 2*x+1);
//   }
//
//   void update(int l, int r, int v, int x = 1)
//   {
//     int lx = len[x][0], rx = len[x][1];
//     item a = single(v);
//     if(r<=lx || rx<=l) return;
//     if(l<=lx && rx<=r) {merge(x, a); return;}
//     push(x);
//     update(l, r, v, 2*x);
//     update(l, r, v, 2*x+1);
//   }
// };

// void solvee()
// {
//   int n; cin >> n;
//   int arr(n); cin >> arr;
//   int ans(n+1, -1);
//   fr(i,0,n)
//   {
//     if(arr[i]==0) ans[i]=0;
//     else if(i && arr[i]<arr[i-1]) ans[i-1]=1, ans[i]=0;
//     else if((arr[i]-1)<i) ans[i]=0;
//     else if((arr[i]-1)>(n-i-1)) ans[i]=1;
//   }
//   int fs = 0;
//   fr(i,0,n)
//   {
//     if(!fs && arr[i])
//     {
//       fr(j,i,i+arr[i]) ans[i]=1;
//       ans[i+arr[i]]=0;
//       fs=1;
//     }
//   }
//   SegTree st(n, vi(n,0));
//   int rst = 0;
//   fr(i,0,n)
//   {
//     int x = arr[i] - st.query(i);
//     if(rst==1 && ans[i]==1) st.update(i,i+1, i);
//     else if(ans[i]==0) rst=0;
//     else
//     {
//       // rst==0
//       int x = arr[i] - st.query(i);
//       if(x)
//       {
//         ans[i]=1;
//         st.update(i,i+x, x);
//         rst=1;
//       }
//       else
//       {
//         rst=0;
//       }
//     }
//   }
// }


void solve()
{
  int n; cin >> n;
  vi arr(n); cin >> arr;
  vi ans(n+1, -1);
  int st = 0;
  fr(i,0,n)
  {
    if(arr[i]==0) ans[i]=0;
    else if(!i || arr[i-1]==0) ans[i]=1, st = i;
    else if(i && arr[i]<arr[i-1]) ans[i]=0;
    else if((arr[i]-1)<i) ans[i]=0;
    else if((arr[i]-1)>(n-i-1)) ans[i]=1;
  }
  dnl(ans);
  int curr = -1;
  fr(i,0,n)
  {
    if(!arr[i]) continue;
    int nxt = arr[i] - (i-st)*ans[i];
    frr(i,curr+1,nxt-1) if(ans[i]==-1) ans[i]=1; if(ans[nxt]==-1) ans[nxt]=0;
    dsp(ans); dsp(curr); dnl(nxt);
    curr = nxt;
  }
  ans.pop_back();
  cnl(ans);
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    //tc(tno);
    solve();
  }
}
// curr = x
// L = arr[i]-ans[i];
// (curr, L] -> all ones.
// 2 4 2 4
// 1 1 0 1
//
// 1 1 0 1
// 1 1 0 1
// 0 1 1 1
// 0 1 1 1
