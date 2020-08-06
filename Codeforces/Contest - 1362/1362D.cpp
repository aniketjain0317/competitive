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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 500001
// #define int int16_t;
// #define ll int64_t;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

vi adj[N];
vi topics[N];
vi tpnode[N];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int n,m,flag=0; cin >> n >> m;
  fr(i,0,m)
  {
    int a,b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int ls[n+1]={};
  fr(i,0,n)
  {
    int x; cin >> x;
    ls[i+1]=x;
    topics[x].pb(i+1);
  }

  for( auto v: topics)
  {
    for(auto i: v)
    {
      if(ls[i]!=1)
      {
        int check[ls[i]+1]={};
        for(auto y: tpnode[i])
        {
          check[y]=1;
        }
        fr(j,1,ls[i])
        {
          if(check[j]==0) {cnl(-1); return 0;}
        }
        // if(check[i]==1) {cnl(-2); return 0;}
      }
      for (auto x: adj[i])
      {
        if(ls[x]>ls[i])
        {tpnode[x].pb(ls[i]);}
        else if(ls[x]==ls[i]) {cnl(-1); return 0;}
      }
    }
  }

  for( auto v: topics)
  {
    for(auto x: v)
    csp(x);
  }
  cout << endl;
}
