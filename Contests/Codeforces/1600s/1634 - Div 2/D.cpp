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

vi rec(vector<int> &arr)
{
  int n = arr.size();
  if(n<=2) return arr;
  if(n==3)
  {
    frr(i,1,n)
    {
      int f = 0;
      fr(j,0,3) if(arr[j]==i) f=1;
      if(f) continue;
      arr.pb(i); n++;
      break;
    }
  }
  auto query = [](int i, int j, int k)
  {
    csp("?"); csp(i); csp(j); cnl(k);
    int x; cin >> x;
    return x;
  };
  vi poss;
  for(int i = 0; i<n; i+=4)
  {
    if((i+3)>=n) // TODO
    {
      fr(j,i,n) poss.pb(arr[j]);
      continue;
    }
    vi ch(4);
    ch[0] = query(arr[i+1],arr[i+2],arr[i+3]);
    ch[1] = query(arr[i],arr[i+2],arr[i+3]);
    ch[2] = query(arr[i],arr[i+1],arr[i+3]);
    ch[3] = query(arr[i],arr[i+1],arr[i+2]);
    int x = maxe(ch);
    fr(j,0,4) if(ch[j]!=x) poss.pb(arr[i+j]);
  }
  return rec(poss);
}

void solve()
{
  int n; cin >> n;
  vi arr(n);
  fr(i,0,n) arr[i]=i+1;
  vi ans = rec(arr);
  if(ans.size()==1) ans.pb(1);
  csp("!"), csp(ans[0]), cnl(ans[1]);
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
    solve();
  }
}
