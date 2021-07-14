// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
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
const ll INF = 1000000007;
const int N = 100005;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,k,x; cin >> n >> k;
  if(n%2==1 && k%2==0) {cnl(-1); return 0;}
  int r = n%k;

  if(n%k==0)
  {
    int ans = 0;
    for(int i = 1; i<=n; i+=k)
    {
      csp("?");
      fr(j,0,k) csp(i+j);
      cout << endl; cin >> x; ans^=x;
    }
    csp("!"); cnl(ans); return 0;
  }

  if(k%2==0)
  {
    int ans = 0;
    for(int i = 1; i<=n; i+=k)
    {
      csp("?");
      fr(j,0,k) csp(i+j);
      cout << endl; cin >> x; ans^=x;
    }
    int r1 = n - r + 1;
    int r2 = r1 + r/2;
    int rx = k - r/2;
    csp("?");
    fr(i,r1,r2) csp(i);
    cout << endl; cin >> x; ans^=x;

    csp("?");
    frr(i,r2,n) csp(i);
    cout << endl; cin >> x; ans^=x;

    csp("!"); cnl(ans); return 0;
  }
  else
  {
    int r = n%k;
    int ans = 0;
    for(int i = 1; i<=n; i+=k)
    {
      csp("?");
      fr(j,0,k) csp(i+j);
      cout << endl; cin >> x; ans^=x;
    }

    if(r%2==0)
    {
      int r1 = n - r + 1;
      int r2 = r1 + r/2;
      int rx = k - r/2;
      csp("?");
      fr(i,r1,r2) csp(i);
      cout << endl; cin >> x; ans^=x;

      csp("?");
      frr(i,r2,n) csp(i);
      cout << endl; cin >> x; ans^=x;

      csp("!"); cnl(ans); return 0;
    }
    else
    {
      int rr = k - r;
      csp("?");
      frr(i,1,rr/2) csp(i);
      cout << endl; cin >> x; ans^=x;

      csp("?");
      frr(i,rr/2+1,rr) csp(i);
      cout << endl; cin >> x; ans^=x;


    }
  }
}

// 11%5: 1
// 1, 2, 3, 4, 5

//

// even, odd
// odd, odd
// odd, even
// even, even
