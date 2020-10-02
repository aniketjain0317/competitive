// Problem
//

#include <bits/stdc++.h>
using namespace std;



// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
//
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
//
// #endif  /* _USE_MATH_DEFINES */


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
#define N 1e5
#define INF 1e9+5

typedef long long ll;
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
  // freopen("myans.txt","w",stdout);
  test(t)
  {
    int n;ll l; cin >> n >> l;
    ll a[n];
    cinp(n,a);
    long double dist[n+1]={};
    dist[0]=a[0];
    dist[n]=l-a[n-1];
    fr(i,1,n) dist[i]=a[i]-a[i-1];

    long double inc[n+2]={};
    long double dec[n+2]={};
    inc[0]=0; dec[n+1]=0;
    fr(i,1,n+2) inc[i]=inc[i-1]+dist[i-1]/(i);
    for(int i=n;i>=0;i--) dec[i]=dec[i+1]+dist[i]/(n-i+1);

    int r=-4;
    fr(i,0,n+2)
    {
      if(dec[i]==inc[i]) {cnl(inc[i]); r=-5; break;}
      if(dec[i]<inc[i]) {r=i-2; break;}
    }
    if(r==-5) continue;

    // csp("(Z)"); show1d(n+1,dist);
    // csp("A"); show1d(n+2,inc);
    // csp("B"); show1d(n+2,dec);
    // cnl("C "<< r);
    long double ans=dec[r+1];
    if(r!=-4) ans+=(inc[r+1]-dec[r+1])*(r+2)/(n+2);
    else
    {
      ans=inc[n] * (n+1)/(n+2);
    }
    cnl(ans);
  }
}
