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
    int cumrows[n]={};
    int truerows[n]={};
    int known[n]={};
    int cummat[n][n]={};
    int truemat[n][n]={};
    fr(i,0,n)
    {
      int ans;
      con(i+1,1,n,n); cin >> ans;
      if(ans==0)
      {
        fr(j,i,n)
        {
          known[j]=1;
        }
        break;
      }
      if(ans==(n-i)*n) {fr(j,i,n)
      {
        known[j]=1;
        fr(k,0,n) truemat[j][k]=1;
      }break;};
      if(i==0) cumrows[i]=ans;
      else
      {
        cumrows[i]=ans;
        truerows[i-1]=cumrows[i-1]-cumrows[i];
        if(i==n-1) truerows[i]=ans;
      }
    }
    fr(i,0,n) fr(j,0,n)
    {
      if(j==0) {cummat[i][j]=truerows[i]; continue;}
      if(known[i]) break;
      int ans;
      con(i+1,j+1,i+1,n); cin >> ans;

      cummat[i][j]=ans;
      truemat[i][j-1]=cummat[i][j-1]-cummat[i][j];
      if(j==n-1) truemat[i][j]=ans;
      // cnl("ADDED"<<i<<j-1<<truemat[i][j-1]);
      if(ans==0) break;
      if(ans==(n-j))
      {
          // cnl("MASS"<<i<<j);
          fr(k,j,n) truemat[i][k]=1;
          break;
      }
    }
    // fr(i,0,n) fr(j,0,n) {con(i+1,j+1,i+1,j+1); fflush(stdout); cout.flush(); cin >> truemat[i][j];}
    cnl(2);
    show2d(n,n,truemat);
    int x; cin >> x;
    if(x==-1) exit(-1);
  }
}
