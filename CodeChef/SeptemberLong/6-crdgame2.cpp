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
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); ll arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define INF 1e9+7L

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

ll xabc = 1e9+7;
ll fac[]={};

// Returns value of Binomial Coefficient C(n, k)
const int N = 1000005;
    using namespace std;
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
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

ll power(ll x, ll y, ll p)
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
            // equal to p

    while (y > 0)
    {
    // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

    // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  InverseofNumber(xabc);
  InverseofFactorial(xabc);
  factorial(xabc);
  test(t)
  {
    int n; cin >> n;
    // cnl("A "<<n);
    ll arr[n];
    fr(i,0,n) cin >> arr[i];
    // fr(i,0,n) arr[i]=1;
    ll max=0;
    int maxc=0;
    fr(i,0,n)
    {
      if(arr[i]==max) maxc++;
      else if(arr[i]>max)
      {
        max=arr[i];
        maxc=1;
      }
    }
    if(maxc%2)
    {
      // cnl(maxc);
      cnl(power(2,n,xabc));
    }
    else
    {
      ll ans = power(2,n,xabc);
      ll p2 = power(2,n-maxc,xabc);
      ll bin = Binomial(maxc,maxc/2,xabc)%xabc;
      p2 = (p2*bin)%xabc;
      ans = (ans-p2)%xabc;
      if(ans<0) ans+=xabc;
      cnl(ans);
    }
  }
}
