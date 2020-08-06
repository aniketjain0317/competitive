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
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int n,q; cin >> n >> q;
  ll height[n];
  cinp(n,height);
  ll taste[n];
  cinp(n,taste);
  int nextr[n]={},nextl[n]={};
  unordered_map<ll,int> mapr[n],mapl[n];
  fr(i,0,n)
  {
    nextr[i]=-1;
    fr(j,i+1,n)
    {
      if(height[i]<height[j])
      {
          nextr[i]=j;
          nextl[j]=i;
          break;
      }
    }
  }
  for(int i=n-1;i>=0;i--)
  {
    nextl[i]=-1;
    for(int j=i-1;j>=0;j++)
    {
      if(height[i]<height[j])
      {
          nextl[i]=j;
          break;
      }
    }
  }

  for(int i=n-1;i>=0;i--)
  {
    int nx = nextr[i];
    if(nx==-1) continue;
    mapr[i][nx]=height[i]+height[nx];
    if(!mapr[nx].empty()) for(auto p: mapr[nx])
    {
      mapr[i][p.fs]=height[i]+p.sn;
    }
  }
  for(int i=0;i<n;i++)
  {
    int nx = nextl[i];
    if(nx==-1) continue;
    mapl[i][nx]=height[i]+height[nx];
    if(!mapl[nx].empty()) for(auto p: mapl[nx])
    {
      mapl[i][p.fs]=height[i]+p.sn;
    }
  }

  fr(i,0,q)
  {
    int a,b,c; cin >> a >> b >> c;
    if(a==2)
    {
      if(b>c)
      {
        if(mapl[c-1].find(b-1)==mapl[c-1].end()) cnl(-1);
        else cnl(mapl[c-1][b-1]);
      }
      else
      {
        if(mapr[b-1].find(c-1)==mapl[b-1].end()) cnl(-1);
        else cnl(mapl[b-1][c-1]);
      }
    }
  }
}
