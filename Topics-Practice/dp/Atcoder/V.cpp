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

ll MOD = 1000000007;
const ll INF = 1LL<<62;
const int N = 100005;

// CREDITS: CF - madhur4127
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


  friend Modular inverse(Modular a) {
    mo x = 1, y = 0;
    mo x1 = 0, y1 = 1, a1 = a.value, b1 = MOD;
    while (b1) {
        mo q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return x;
  }
  // friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
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

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m; cin >> n; cin >> MOD;
  vvi adj(n);
  fr(i,0,n-1)
  {
    int u,v; cin >> u >> v; u--, v--;
    adj[u].pb(v); adj[v].pb(u);
  }

  vector<mo> ans(n,0), subs(n,1);
  function<void(int,int)> getSubs = [&](int node, int parent)
  {
    for(auto &child: adj[node]) if(child!=parent) getSubs(child,node);
    for(auto &child: adj[node]) if(child!=parent) subs[node]*=subs[child];
    subs[node]+=1;
  };
  function<void(int,int)> getAns = [&](int node, int parent)
  {
    // (sn - 1)(ap+sn)/sn
    // sn-1 + (ap*sn - ap)/sn
    ans[node] = subs[node]-1;
    if(node!=parent) ans[node] *= 1 +  (ans[parent]/subs[node]);
    for(auto &child: adj[node]) if(child!=parent) getAns(child,node);
  };

  getSubs(0,0);
  getAns(0,0);
  // cnl(subs);
  cnl(ans);
}
