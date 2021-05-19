// Problem
//

#include <bits/stdc++.h>
using namespace std;

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
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int mo;
#define ll mo;
// #define endl '\n'

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const long long INF = 1000000007;
const int N = 100005;

template <long long MOD=INF>
struct Modular {
  long long value;
  static const long long MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
typedef Modular<INF> mo;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res += a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a)
{
  return binpow(a,INF-2);
}


vi adj2[N];
vi adj[N];

int ans=0;
bool visited[N]={};

void rootTree(int node)
{
  visited[node]=1;
  for(auto &child: adj2[node])
  {
    if(!visited[child])
    {
      adj[node].pb(child);
      rootTree(child);
    }
  }
}

vi val(N,1);
void calcVal(int node)
{
  int x=0, x2 = 0;
  for(auto &child: adj[node]) calcVal(child);
  for(auto &child:adj[node])
  {
    x=am(x,val[child]);
    x2=am(x2, mm(val[child], val[child]));
  }
  val[node] = am(mm(2,x),1);
  ans = am(ans,1);
  ans = am(ans,x);
  ans = am(ans,am(mm(x,x), -1*x2));
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
    int n;
    cin >> n;

    frr(i,0,n) adj2[i].clear(), adj[i].clear();
    frr(i,0,n) visited[i]=0;
    frr(i,0,n) val[i]=1;
    ans = 0;

    fr(i,0,n-1)
    {
      int a,b; cin >> a >> b;
      adj2[a].pb(b);
      adj2[b].pb(a);
    }
    rootTree(1);
    calcVal(1);
    cnl(ans);
  }
}
