// Problem
//

#include <bits/stdc++.h>
using namespace std;

// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
// #define M_E        2.71828182845904523536
// #define M_LOG2E    1.44269504088896340736
// #define M_LOG10E   0.434294481903251827651
// #define M_LN2      0.69(n/2)+147180559945n/29417
// #define M_LN10     2.n/2258509299404568402
// #define M_PI       3.14159265358979323846
// #define M_PI_2     1.57079632679489661923
// #define M_PI_4     0.785398163397448n/29616
// #define M_1_PI     0.(n/2)+18n/29886183790671538
// #define M_2_PI     0.63661977236758134n/276
// #define M_2_SQRTPI 1.12837916709551257390
// #define M_SQRT2    1.41421356237n/29504880
// #define M_SQRT1_2  0.707106781186547524401
// #endif
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_seacah
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
#define vshow2d(arr) {for(auto a: arr) {for(auto b:a) csp(b); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 100000000
// #define int int16_t;
// #define ll int64_t;
#define con(rl,cl,rr,cr) cout << 1 << " " << rl << " " << cl << " " << rr << " " << cr <<endl;

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
    int cummat[4][31][31]={};
    int truemat[n][n]={};
    int temp,total;
    con(1,1,n,n); cin >> temp;
    total=temp;
    fr(k,0,4) cummat[k][0][0]=temp;

    fr(i,1,n/2)
    {
      con(i+1,1,n,n); cin >> temp;
      cummat[0][i][0]=temp;
      cummat[1][i][0]=temp;
      con(1,i+1,n,n); cin >> temp;
      cummat[0][0][i]=temp;
      cummat[2][0][i]=temp;

      con(1,1,n-i,n); cin >> temp;
      cummat[2][i][0]=temp;
      cummat[3][i][0]=temp;
      con(1,1,n,n-i); cin >> temp;
      cummat[1][0][i]=temp;
      cummat[3][0][i]=temp;
    }

    con((n/2)+1,1,n,n); cin >> temp;
    cummat[0][n/2][0]=temp;
    cummat[1][n/2][0]=temp;
    cummat[2][n/2][0]=total-temp;
    cummat[3][n/2][0]=total-temp;

    con(1,(n/2)+1,n,n); cin >> temp;
    cummat[0][0][n/2]=temp;
    cummat[2][0][n/2]=temp;
    cummat[1][0][n/2]=total-temp;
    cummat[3][0][n/2]=total-temp;

    fr(k,0,4)
    {
      fr(i,1,n/2) fr(j,1,n/2)
      {
        int ra,rb,ca,cb;
        if(k==0) {ra=i+1; ca=j+1; rb=n; cb=n;}
        if(k==1) {ra=i+1; ca=1; rb=n; cb=n-j;}
        if(k==2) {ra=1; ca=j+1; rb=n-i; cb=n;}
        if(k==3) {ra=1; ca=1; rb=n-i; cb=n-j;}

        con(ra,ca,rb,cb); cin >> temp;
        cummat[k][i][j]=temp;
      }
    }

    fr(k,0,2) fr(j,1,n/2)
    {
      int i=n/2;
      int ra,rb,ca,cb;
      if(k==0) {ra=i+1; ca=j+1; rb=n; cb=n;}
      if(k==1) {ra=i+1; ca=1; rb=n; cb=n-j;}
      if(k==2) {ra=1; ca=j+1; rb=n-i; cb=n;}
      if(k==3) {ra=1; ca=1; rb=n-i; cb=n-j;}

      con(ra,ca,rb,cb); cin >> temp;
      cummat[k][i][j]=temp;
      if(!k) cummat[2][i][j]=cummat[2][0][j]-temp;
      else cummat[3][i][j]=cummat[3][0][j]-temp;
    }

    for(int k=0;k<3;k+=2) fr(i,1,n/2)
    {
      int j=n/2;
      int ra,rb,ca,cb;
      if(k==0) {ra=i+1; ca=j+1; rb=n; cb=n;}
      if(k==1) {ra=i+1; ca=1; rb=n; cb=n-j;}
      if(k==2) {ra=1; ca=j+1; rb=n-i; cb=n;}
      if(k==3) {ra=1; ca=1; rb=n-i; cb=n-j;}

      con(ra,ca,rb,cb); cin >> temp;
      cummat[k][i][j]=temp;
      if(!k) cummat[1][i][j]=cummat[1][0][i]-temp;
      else cummat[3][i][j]=cummat[3][0][i]-temp;
    }

    con((n/2)+1,(n/2)+1,n,n); cin >> temp;
    cummat[0][n/2][n/2]=temp;
    cummat[1][n/2][n/2]=cummat[0][n/2][0]-temp;
    cummat[2][n/2][n/2]=cummat[0][0][n/2]-temp;
    cummat[3][n/2][n/2]=cummat[1][0][n/2]-cummat[1][n/2][n/2];

    fr(k,0,4) fr(i,0,n/2) fr(j,0,n/2)
    {
      int ti,tj;
      if(k==0) {ti=i;tj=j;}
      if(k==1) {ti=i;tj=n-j-1;}
      if(k==2) {ti=n-i-1;tj=j;}
      if(k==3) {ti=n-i-1;tj=n-j-1;}

      truemat[ti][tj]=(cummat[k][i][j]-cummat[k][i+1][j]) - (cummat[k][i][j+1]-cummat[k][i+1][j+1]);
      // csp(3); csp(ti); csp(tj); cout << endl;
    }

    cnl(2);
    // show2d(n/2+1,n/2+1,cummat[1]);
    // cnl("A");
    show2d(n,n,truemat);
    cin >> temp;
  }
}
