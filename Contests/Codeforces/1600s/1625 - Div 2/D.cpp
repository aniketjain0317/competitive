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

int search(int n,vector<int> &A){
    int l=0, r=A.size(), res=0;
    for(int i=30;i>-1;i--){
        int m=lower_bound(A.begin()+l, A.begin()+r, res^(1<<i))-A.begin();
        if((1<<i) & n){
            if(l==m) res^=(1<<i);
            else r=m;
        }
        else if(m!=r) l=m, res^=(1<<i);
    }
    return res;
}


int k, msb = 0;
vi rec(vector<int> &arr)
{
  vi ans;
  sort(all(arr));
  // O(32*arr.size()) memory
  frrb(i,31,msb+1)
  {
    vi arr2;
    while(arr.back() & (1LL<<i))
    {
      arr2.pb(arr.back() ^ (1LL<<i));
      arr.pop_back();
    }
    if(arr2.empty()) continue;
    vi ans2 = rec(arr2);
    if(ans2.empty()) ans2.pb(arr2[0]);
    // dsp(i); dsp(arr2); dnl(ans2);
    for(auto x: ans2) ans.pb(x^(1LL<<i));
  }
  if(arr.empty()) return ans;

  vi arr3;
  while(arr.back() & (1LL<<msb))
  {
    arr3.pb(arr.back());
    arr.pop_back();
  }
  if(arr3.empty())
  {
    ans.pb(arr[0]);
    return ans;
  }

  // O(1) MEMORY
  int res=0, x =0,y=0;
  for(auto i: arr3) if(chmax(res,search(i,arr)^i)) x=i,y=x^res;
  // dsp(res); dsp(x); dnl(y);
  ans.pb(x);
  if(res>=k) ans.pb(y);
  return ans;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n; cin >> n >> k;
  int kk = k;
  do
  {
    msb++;
    kk>>=1;
  }
  while(kk);
  msb--;
  // dnl(msb);
  vi arr(n); cin >> arr;
  map<int,int> mp;
  fr(i,0,n) mp[arr[i]] = i+1;
  vi ans;
  if(!k)
  {
    cnl(n);
    frr(i,1,n) cnl(i);
    return 0;
  }
  else ans = rec(arr);
  if(ans.size()<=1) {cnl(-1); return 0;}
  for(auto &x: ans) x = mp[x];
  cnl(ans.size()); cnl(ans);
}
