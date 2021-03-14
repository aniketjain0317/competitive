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
#define con(rl,cl,rr,cr) cout << 1 << " " << rl << " " << cl << " " << rr << " " << cr <<endl;
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) {csp(arr[i][j]); fflush(stdout); cout.flush();} cout << endl;}
#define N 100000000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  test(t)
  {
    int n,p; cin >> n >> p;
    int truemat[n][n]={};
    vi cummat[4][n+1];
    fr(k,0,4) fr(i,0,n+1) cummat[k][i].resize(n+1,0);
    fr(i,0,n/2+1) fr(j,0,n/2+1) {con(i+1,j+1,n,n); cin >> cummat[0][i][j];}



    fr(i,0,n/2) fr(j,0,n/2) truemat[i][j]=(cummat[0][i][j]-cummat[0][i+1][j]) - (cummat[0][i][j+1]-cummat[0][i+1][j+1]);

    fr(i,0,n/2+1) fr(j,0,n/2+1)
    {
      con(i+1,j+1,n,n); cin >> cummat[0][i][j];
      if(!i && !j)
      {
        fr(k,1,4) cummat[k][i][j]=cummat[0][i][j];
        continue;
      }
      con(i+1,1,n,n-j); cin >> cummat[1][i][j];
      con(1,1,n-i,n-j); cin >> cummat[2][i][j];
      con(1,j+1,n-i,n); cin >> cummat[3][i][j];
    }
    fr(k,0,4) fr(i,0,n/2) fr(j,0,n/2)
    {
      int x = (cummat[k][i][j]-cummat[k][i+1][j]) - (cummat[k][i][j+1]-cummat[0][i+1][j+1]);
      if(k==0) truemat[i][j]=x;
      if(k==1) truemat[i][n-j-1]=x;
      if(k==2) truemat[n-i-1][n-j-1]=x;
      if(k==3) truemat[n-i-1][j]=x;
    }


    cnl(2);
    show2d(n,n,truemat);
    int x; cin >> x;
    if(x==-1) exit(-1);
  }
}
