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
    int cummat0[n+1][n+1]={};
    int cummat1[n+1][n+1]={};
    int cummat2[n+1][n+1]={};
    int cummat3[n+1][n+1]={};
    int known[4]={};
    vi coords[4];
    // fr(i,0,n/2+1) fr(j,0,n/2+1) {con(i+1,j+1,n,n); cin >> cummat0[i][j];}

    // fr(i,0,n/2) fr(j,0,n/2) truemat[i][j]=(cummat0[i][j]-cummat0[i+1][j]) - (cummat0[i][j+1]-cummat0[i+1][j+1]);

    fr(i,0,n/2+1) fr(j,0,n/2+1)
    {
      ll cor[4][2]={};
      ll coc[4][2]={};
      cor[0][0]=i+1; cor[0][1]=n;
      cor[1][0]=i+1; cor[1][1]=n;
      cor[2][0]=1; cor[2][1]=n-i;
      cor[3][0]=1; cor[3][1]=n-i;

      coc[0][0]=j+1; coc[0][1]=n;
      coc[1][0]=1; coc[1][1]=n-j;
      coc[2][0]=1; coc[2][1]=n-j;
      coc[3][0]=j+1; coc[3][1]=n-j;
      if(!known[3])
      {
        con(cor[0][0],coc[0][0],cor[0][1],coc[0][1]);
        cin >> cummat0[i][j];
        if(!cummat0[i][j]) {known[0]=1; coords[0].pb(i); coords[0].pb(j);}
      }
      if(!i && !j)
      {
        cummat1[i][j]=cummat0[0][0];
        cummat2[i][j]=cummat0[0][0];
        cummat3[i][j]=cummat0[0][0];
        continue;
      }
      if(!known[2])
      {
        int ch=0;
        fr(i,0,1) if(cor[1][0]==cor[i][0] && cor[1][1]==cor[i][1] && coc[1][0]==coc[i][0] && coc[1][1]==coc[i][1])
        {
          if(i==0) cummat1[i][j]=cummat0[i][j];
          ch=1; break;
        }
        if(!ch) {con(cor[1][0],coc[1][0],cor[1][1],coc[1][1]);
        cin >> cummat1[i][j];}
        if(!cummat1[i][j]) {known[1]=1; coords[1].pb(i); coords[1].pb(j);}
      }
      if(!known[1])
      {
        int  ch=0;
        fr(i,0,2) if(cor[2][0]==cor[i][0] && cor[2][1]==cor[i][1] && coc[2][0]==coc[i][0] && coc[2][1]==coc[i][1])
        {
          if(i==0) cummat2[i][j]=cummat0[i][j];
          if(i==1) cummat2[i][j]=cummat1[i][j];
          ch=1; break;
        }
        if(!ch) {con(cor[2][0],coc[2][0],cor[2][1],coc[2][1]);
        cin >> cummat2[i][j];}
        if(!cummat2[i][j]) {known[2]=1; coords[2].pb(i); coords[2].pb(j);}
      }
      if(!known[0])
      {
        int ch=0;
        fr(i,0,3) if(cor[3][0]==cor[i][0] && cor[3][1]==cor[i][1] && coc[3][0]==coc[i][0] && coc[3][1]==coc[i][1])
        {
          if(i==0) cummat1[i][j]=cummat0[i][j];
          if(i==1) cummat1[i][j]=cummat1[i][j];
          if(i==2) cummat1[i][j]=cummat2[i][j];
          ch=1; break;
        }
        if(!ch) {con(cor[3][0],coc[3][0],cor[3][1],coc[3][1]);
        cin >> cummat3[i][j];}
        if(!cummat3[i][j]) {known[3]=1; coords[3].pb(i); coords[3].pb(j);}
      }
    }

    fr(i,0,n/2) fr(j,0,n/2)
    {
      int x = (cummat0[i][j]-cummat0[i+1][j]) - (cummat0[i][j+1]-cummat0[i+1][j+1]);
      truemat[i][j]=x;
    }
    fr(i,0,n/2) fr(j,0,n/2)
    {
      int x = (cummat1[i][j]-cummat1[i+1][j]) - (cummat1[i][j+1]-cummat1[i+1][j+1]);
      truemat[i][n-j-1]=x;
    }
    fr(i,0,n/2) fr(j,0,n/2)
    {
      int x = (cummat2[i][j]-cummat2[i+1][j]) - (cummat2[i][j+1]-cummat2[i+1][j+1]);
      truemat[n-i-1][n-j-1]=x;
    }
    fr(i,0,n/2) fr(j,0,n/2)
    {
      int x = (cummat3[i][j]-cummat3[i+1][j]) - (cummat3[i][j+1]-cummat3[i+1][j+1]);
      truemat[n-i-1][j]=x;
    }


    cnl(2);
    show2d(n,n,truemat);
    int x; cin >> x;
    if(x==-1) exit(-1);
  }
}
