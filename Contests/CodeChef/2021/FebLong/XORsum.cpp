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
#define endl '\n'
#define intt int32_t
#define int long long
#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))
#define dm(a,b) MOD(MOD(a)*modInverse(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef complex<double> cd;
typedef vector<cd> vcd;

const ll INF = 998244353;
const int N = 200005;
const int B = 32;
const double PI = acos(-1);

map<double,ll> minv;
map<pi,ll> mncr;

ll fac[N]={};

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}
double MOD(double a)
{
  a = fmod(a,INF);
  while(a<0) a+=INF;
  return a;
}
cd MOD(cd a)
{
  return cd(MOD(real(a)), MOD(imag(a)));
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mm(res, a);
        a = mm(a,a);
        b >>= 1;
    }
    return res;
}
double binpow(double a, long long b) {
    double res = 1;
    while (b > 0) {
        if (b & 1)
            res = mm(res, a);
        a = mm(a,a);
        b >>= 1;
    }
    return res;
}
double modInverse(ll a)
{
  if(minv.find(a)==minv.end()) minv[a]=binpow(a,INF-2);
  return minv[a];
}
// ll modInverse(ll a)
// {
//   if(minv.find(a)==minv.end()) minv[a]=binpow(a,INF-2);
//   return minv[a];
// }

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = am(a0[i], mm( w , a1[i]));
        a[i + n/2] = am(a0[i],mm( w ,-a1[i]));
        if (invert) {
            dm(a[i], 2);
            dm(a[i + n/2], 2);
        }
        w =mm(w,wn);
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i]= mm(fa[i], fb[i]);
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void calcFac(int n)
{
  fac[0]=1;
  frr(i,1,n) fac[i]=mm(fac[i-1],i);
}
ll ncr(int n, int r)
{
  pi p(n,r);
  if(r>n) return 0;
  if(mncr.find(p)==mncr.end()) mncr[p]=dm(fac[n], mm(fac[r], fac[n-r]));
  return mncr[p];
}

ll binomialCoeff(int n, int k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i) {
        res = mm(res,(n - i));
        res = mm(res,modInverse(i + 1));
    }
    return res;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  ainpl(n,arr);
  ainpl(q,queries);
  calcFac(N);
  intt cnt[B]={};
  fr(i,0,n)
  {
    bitset<B> bs(arr[i]);
    fr(b,0,B) if(bs[b]) cnt[b]++;
  }
  vvi v;
  fr(b,0,B)
  {
    int x = cnt[b];
    int y = n-x;
    vi a,c;
    frr(i,0,x) a.pb(binomialCoeff(x,i));
    frr(i,0,y) c.pb(binomialCoeff(y,i));
    v.pb(multiply(a,c));
  }

  for(auto m: queries)
  {
    ll ans=0;
    ll y = ncr(n,m);
    fr(b,0,B)
    {
      ll x= mm(binpow(2LL,b),dm(am(y,-v[b][m]),2));
      ans= am(ans,x);
    }
    cnl(ans);
  }
}
// 4
// 1 3 5 2
// 2
// 1
// 2
// 001,011, 101, 010
