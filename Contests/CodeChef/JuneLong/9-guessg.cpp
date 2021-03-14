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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
void nextq(ll l, ll r, int ct, ll cts, ll cte);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  ll n; cin >> n;
  nextq(0,n,0,0,0);
}

void nextq(ll l, ll r, int ct, ll cts, ll cte)
{
  char req='a',reqp='b';
  int same=0;
  if(r>=l)
  {

    if(!ct)
    {
      ll m = l+ (r-l)/2;
      ll mr = m + (r-m)/2;
      ll ml = l + (m-l)/2;
      cnl(m); cin >> req;
      if(req=='G')
      {
        cnl(mr); cin >> req;
        if(req=='G') nextq(m+1,r,0,0,0);
        else if(req=='L')
        {
          cnl(mr); cin >> req;
          if(req=='L') nextq(l,mr-1,0,0,0);
          else if(req=='G')
          {
            cnl(ml); cin >> req;
            if(req=='G') nextq(ml+1,r,0,0,0);
            else if(req=='L') nextq(l,r,1,ml-1,mr+1);
          }
        }
      }
      else if(req=='L')
      {
        cnl(ml); cin >> req;
        if(req=='L') nextq(l,m+1,0,0,0);
        else if(req=='G')
        {
          cnl(ml); cin >> req;
          if(req=='G') nextq(ml+1,r,0,0,0);
          else if(req=='L')
          {
            cnl(mr); cin >> req;
            if(req=='L') nextq(l,mr-1,0,0,0);
            else if(req=='G') nextq(l,r,1,ml-1,mr+1);
          }
        }
      }
    }
    else if(ct)
    {
      ll m =0;
      if(r-cte>cts-l) m=cte;
      else m = cts;

      ll mr = cte + (r-cte)/2;
      ll ml = l + (cts-l)/2;

      cnl(m); cin >> req;
      if(req=='G')
      {
        cnl(mr); cin >> req;
        if(req=='G') nextq(m+1,r,1,cts,cte+1);
        else if(req=='L')
        {
          cnl(mr); cin >> req;
          if(req=='L') nextq(l,mr-1,1,cts,cte+1);
          else if(req=='G')
          {
            cnl(ml); cin >> req;
            if(req=='G') nextq(ml+1,r,1,cts-1,cte+1);
            else if(req=='L') nextq(l,r,1,ml-1,mr+1);
          }
        }
      }
      else if(req=='L')
      {
        cnl(ml); cin >> req;
        if(req=='L') nextq(l,m+1,1,cts-1,cte);
        else if(req=='G')
        {
          cnl(ml); cin >> req;
          if(req=='G') nextq(ml+1,r,1,cts-1,cte);
          else if(req=='L')
          {
            cnl(mr); cin >> req;
            if(req=='L') nextq(l,mr-1,1,cts-1,cte+1);
            else if(req=='G') nextq(l,r,1,ml,mr);
          }
        }
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
