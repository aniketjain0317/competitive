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
#define cinp(n,arr) fr(ixx,0,n) read(arr[ixx]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(ixx,0,n) {csp(arr[ixx]);}cout<<endl;}
#define show1d(n,arr) fr(ixx,0,n) {csp(arr[ixx]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(ixx,0,n) {int m = arr[ixx].size(); fr(jxx,0,m) csp(arr[ixx][jxx]); cout << endl;}}
#define show2d(n,m,arr) {fr(ixx,0,n) {fr(jxx,0,m) csp(arr[ixx][jxx]); cout << endl;}}

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<ll> vi;
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
    int n; cin >> n;
    vvi arr(n);
    fr(i,0,n)
    {
      ll x,y; cin >> x >> y;
      arr[i].pb(max(x,y));
      arr[i].pb(min(y,x));
      arr[i].pb(i);
    }
    sort(all(arr));
    vi mn(n,arr[0][1]), mni(n,0);
    fr(i,1,n)
    {
      if(arr[i][1]<mn[i-1]) {mn[i]=arr[i][1]; mni[i]=i;}
      else {mn[i]=mn[i-1]; mni[i]=mni[i-1];}
    }
    vi sans(n,-1);
    int x=-1;
    fr(i,1,n)
    {
      if(arr[i][0]>arr[i-1][0]) x=i-1;
      if(x>=0 && arr[i][1]>mn[x]) sans[i]=mni[x];
    }
    vi ans(n,-1);
    fr(i,0,n) if(sans[i]!=-1) ans[arr[i][2]]=arr[sans[i]][2]+1;
    show1d(n,ans);
  }
}
// 1 1
// 2 2
// 3 2
// 4 4
// -1 0 -1 -1
