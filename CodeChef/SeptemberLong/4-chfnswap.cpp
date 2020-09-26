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
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define INF 1e9+5

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  freopen("myans.txt","w",stdout);
  // fr(t,1,1000)
  test(t)
  {
    ll n;
    n=tno;
    // cin >> n;
    ll n2 = n*n;
    ld a1 = (-1.0 + (ld)sqrt(2*n2 + 2*n + 1))/2;
    ld a2 = (-1.0 + (ld)sqrt(2*n2 - 6*n + 9))/2;
    ll ans=0;
    ll s = (n2 + n)/4;
    ll ma = ceil(a2);
    ll mb = floor(a1);
    for(ll m=ma;m<=mb;m++)
    {
      ll m2 = m*m;
      ll d = s - (m+m2)/2;
      ll mn=max(m,d);
      ll mx = min(m+d,n);
      ll a=0;
      if(!d) {a=((m2-m) + (n-m)*(n-m-1))/2;}
      else a=mx-mn;
      ans+=a;
      // csp(n); csp(m); csp(d); cnl(mx-mn);
    }
    if(n%4==1 || n%4==2)
    {
      ans=0;
      // continue;
    }
    // csp(m); cnl(d);
    printf("%lld\n",ans);
  }
}
/*
d+1 - 1
.
(m+1) - (m+1-d)  [if(m>d)]
.
(m+d) - m
.
n - n-d
*/
