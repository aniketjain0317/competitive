// Problem
//

#include <bits/stdc++.h>
using namespace std;

// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
// #define M_E        2.71828182845904523536
// #define M_LOG2E    1.44269504088896340736
// #define M_LOG10E   0.434294481903251827651
// #define M_LN2      0.693147180559945309417
// #define M_LN10     2.30258509299404568402
// #define M_PI       3.14159265358979323846
// #define M_PI_2     1.57079632679489661923
// #define M_PI_4     0.785398163397448309616
// #define M_1_PI     0.318309886183790671538
// #define M_2_PI     0.636619772367581343076
// #define M_2_SQRTPI 1.12837916709551257390
// #define M_SQRT2    1.41421356237309504880
// #define M_SQRT1_2  0.707106781186547524401
// #endif
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1000
#define INF 1000000
#define modp 1000000007
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

long long binpow(int a, int b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long modInverse(int n, long long p)
{
    return binpow(n, p - 2, p);
}

long long nCrModPFermat(int n,
                                 int r, long long p)
{
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    ainp(n,arr);
    map<int,int> freq;
    int maxf=0;
    fr(i,0,n) if(++freq[arr[i]] > maxf) maxf=freq[arr[i]];
    vi nobyf[maxf+1];
    for(auto p: freq) frr(i,1,p.sn) nobyf[i].pb(p.fs);

    ll ans[n+1]={};
    frr(i,1,maxf)
    {
      int sz = nobyf[i].size();
      fr(j,0,sz)
      {
        int x = nobyf[i][j];
        ll a = nCrModPFermat(freq[x],i,modp);
        ll b = binpow(i+1,sz-1-j,modp)%modp;

        cnl("i "<<i<<" j "<<j);
        cnl("A "<<a);
        cnl("B "<<b);
        ans[x]+=(a*b)%modp;
        ans[x]=ans[x]%modp;
      }
    }
    frr(i,1,n) csp(ans[i]);
    cout << endl;
  }
}
