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
#define int long long
// #define endl '\n'
#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 1000005;

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mm(res, a);
        a = mm(a,a);
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a)
{
  return binpow(a,INF-2);
}

ll factorialNumInverse[N + 1];
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
// array to store factorial of first N numbers
ll fact[N + 1];
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
       factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}


void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

ll Binomial(ll N, ll R, ll p)
{
    if(N<R) return 0;
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  pi moves[8]={{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
  InverseofNumber(INF);
  InverseofFactorial(INF);
  factorial(INF);
  test(t)
  {
    int n,m,k; cin >> n >> m >> k;
    vvi grid(n, vi(m,-1));
    vpi barns;
    fr(i,0,n) fr(j,0,m)
    {
      char c; cin >> c;
      if(c=='X') barns.pb({i,j}), grid[i][j]=0;
    }

    queue<pi> q;
    for(auto &x: barns) q.push(x);

    while(!q.empty())
    {
      auto x = q.front(); q.pop();
      vpi v;
      for(auto &p: moves)
      {
        int a = x.fs+p.fs, b = x.sn+p.sn;
        if(a>=0 && a<n && b>=0 && b<m) v.pb({a,b});
      }

      for(auto &p: v) if(grid[p.fs][p.sn] == -1 || grid[x.fs][x.sn]+1<grid[p.fs][p.sn])
      {
        q.push(p);
        grid[p.fs][p.sn] = grid[x.fs][x.sn]+1;
      }
    }

    int mx = 0;
    fr(i,0,n) fr(j,0,m) mxs(mx, grid[i][j]);

    mx++;
    int mp[mx]={};
    fr(i,0,n) fr(j,0,m) mp[grid[i][j]]++;


    int cum[mx]={};
    cum[0]=mp[0];
    fr(i,1,mx) cum[i]=cum[i-1]+mp[i];

    int ncr[mx]={};
    fr(i,0,mx) ncr[i] = Binomial(cum[i],k,INF);

    int sum = 0;
    fr(i,1,mx) sum = am(sum, mm(am(ncr[i],-ncr[i-1]) ,i));
    sum = mm(sum, modInverse(ncr[mx-1]));
    cnl(sum);
  }
}
