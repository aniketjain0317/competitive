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
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    ainpl(n,arr);
    int sum1=0, sum2=0;
    vi s1, s2;
    int c1=-1, c2=-1;
    vi m1(n), m2(n);
    fr(i,0,n)
    {
      sum1=arr[i]-sum1;
      if(sum1<0) c1=i;
      s1.pb(sum1);
    }
    fr(i,0,n)
    {
      sum2=arr[n-i-1]-sum2;
      if(sum2<0) c2=i;
      s2.pb(sum2);
    }
    frrb(i,n-1,0)
    {
      if(i==n-1) m1[i]=s1[i];
      else m1[i]=min(m1[i+1],s1[i]);
    }
    frrb(i,n-1,0)
    {
      if(i==n-1) m2[i]=s2[i];
      else m2[i]=min(m2[i+1],s2[i]);
    }

    if(c1==-1 || c2==-1) if(!sum1) {cnl("YES"); continue;}

    int flag=0;

    fr(i,0,n-1)
    {
      ll x=(arr[i+1]-arr[i]);
      if(i&1) x=-x;
      if(sum1+2*x==0)
      {
        if(m1[i+1]+2*x>=0 && s1[i]>=x) {flag=1; break;}
      }
      if(sum2+2*x==0)
      {
        if(m2[i+1]+2*x>=0 && s2[i]>=x) {flag=1; break;}
      }
    }
    if(flag) cnl("YES");
    else cnl("NO");
  }
}
