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
#define con(x) cout << x; cout << flush;
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = sizeof(arr)/sizeof(arr[0]); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector <ll> vll;
void nextq(vll ls);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  ll n; cin >> n;
  vll l0;
  l0.pb(1); l0.pb(n);
  nextq(l0);
}

void nextq(vll ls)
{
  int rangeNo = ls.size()/2;
  // THINK ABT THIS CONDITION
  if(ls[rangeNo-1]>=ls[0])
  {
    vll rangeSize;
    fr(i,0,rangeNo) rangeSize.pb(ls[2*i+1]-ls[2*i]);
    ll length = accumulate(rangeSize.begin(),rangeSize.end(),0);
    ll m[5]={1,(length+1)/4,(length+1)/2,(3*length+1)/4,length};


    ll posn[5]={};
    fr(k,0,5)
    {
      fr(i,0,rangeNo)
      {
        if(m[k]<=rangeSize[i])
        {
          m[k] += ls[2*i];
          posn[k]=i;
          break;
        }
        else m[k]-= rangeSize[i];
      }
    }

    cnl("INTERVAL");
    show1d(2*rangeNo,ls);
    vshow1d(m);

    char req;
    vll outLs;
    cnl(m[2]); cin >> req;
    if(req=='G')
    {
      cnl(m[1]); cin >> req;
      if(req=='G')
      {
        int k0=1, k1=4;
        outLs.pb(m[k0]+1);
        fr(i,posn[k0],posn[k1])
        {
          outLs.pb(ls[2*i+1]);
          outLs.pb(ls[2*i+2]);
        }
        outLs.pb(m[k1]);
        nextq(outLs);
      }
      else if(req=='L')
      {
        int k0=0, k1=1, k2=2,k3=4;
        outLs.pb(m[k0]);
        fr(i,posn[k0],posn[k1])
        {
          outLs.pb(ls[2*i+1]);
          outLs.pb(ls[2*i+2]);
        }
        outLs.pb(m[k1]-1);
        outLs.pb(m[k2]+1);
        fr(i,posn[k2],posn[k3])
        {
          outLs.pb(ls[2*i+1]);
          outLs.pb(ls[2*i+2]);
        }
        outLs.pb(m[k3]);
        nextq(outLs);
      }
    }
    else if(req=='L')
    {
      cnl(m[3]); cin >> req;
      if(req=='L')
      {
        int k0=0, k1=3;
        outLs.pb(m[k0]);
        fr(i,posn[k0],posn[k1])
        {
          outLs.pb(ls[2*i+1]);
          outLs.pb(ls[2*i+2]);
        }
        outLs.pb(m[k1]);
        nextq(outLs);
      }
      else if(req=='G')
      {
        int k0=0, k1=2, k2=3,k3=4;
        outLs.pb(m[k0]);
        fr(i,posn[k0],posn[k1])
        {
          outLs.pb(ls[2*i+1]);
          outLs.pb(ls[2*i+2]);
        }
        outLs.pb(m[k1]-1);
        outLs.pb(m[k2]+1);
        fr(i,posn[k2],posn[k3])
        {
          outLs.pb(ls[2*i+1]);
          outLs.pb(ls[2*i+2]);
        }
        outLs.pb(m[k3]);
        nextq(outLs);
      }
    }
    // while(!same)
    // {
    //   cnl(m); cin >> req;
    //   if(req=='E') exit(0);
    //   same = (req==reqp);
    //   reqp=req;
    // }
  }
}
