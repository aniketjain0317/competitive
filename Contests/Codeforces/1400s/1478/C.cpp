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
#define gri greater<ll>
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
#define int ll

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n; cin >> n;
    int m=2*n;
    int arr[m]; cinp(m,arr);
    sort(arr,arr+m,gri());
    int flag=0;
    for(int i=0; i<m;i+=2)
    {
      if(arr[i]!=arr[i+1]) {flag=1; break;}
      if(i<m-2 && arr[i]==arr[i+2]) {flag=1; break;}
    }
    if(flag) {cnl("NO"); continue;}
    int ans[n]={};
    int sum=0;
    fr(i,0,n)
    {
      int j=2*i;
      int x=arr[j]-2*sum;
      if(x<=0 || x%(m-j)!=0) {flag=1; break;}
      ans[i]=x/(m-j);
      sum+=ans[i];
    }

    if(flag) {cnl("NO"); continue;}
    cnl("YES");
  }
}

// -a -b -c c b a
// sum-6a, sum-4b-2a, sum-2c-2b-2a, sum-2c-2b-2a,+2e-2d-2c-2b-2a, +4f-2e-2d-2c-2b-2a
// 6a, 4b+2a, 2c+2b+2a, 2c+2b+2a, 4b+2a, 6a
// na, n-2.b +2a, n-4.c + 2b + 2a

// (a*b)*c=4a-2b-c
//8a-4b-2c-d
// (a*b)*(c*d)=4a-2b-2c+d
// [8,-8,4,-4,1]
0
2 3 7
2*2-3=1
2*1-2=0
a b
// 10 6
// 1111111111
// 0110001110
// 1 10
// 5 9
// 7 10
// 1 7
// 3 5
// 6 10
