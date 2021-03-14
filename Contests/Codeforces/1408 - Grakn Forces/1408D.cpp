// Problem
//

#include <bits/stdc++.h>
using namespace std;



// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
//
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
//
// #endif  /* _USE_MATH_DEFINES */


#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1e5
#define INF 1e9+5

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  int n,m; cin >> n >> m;
  vpi robs(n);
  vpi srch(m);
  fr(i,0,n) cin >> robs[i].fs >> robs[i].sn;
  fr(i,0,m) cin >> srch[i].fs >> srch[i].sn;

  vpi rbtrue, srtrue;
  sort(robs.begin(),robs.end());
  sort(srch.begin(),srch.end());
  int prev=0;
  fr(i,0,n)
  {
    if(rbtrue.empty()) {rbtrue.pb(robs[0]);prev=robs[0].sn; continue;}
    if(robs[i].sn>=prev) continue;
    rbtrue.pb(robs[i]); prev=robs[i].sn;
  }
  fr(i,0,m)
  {
    if(srtrue.empty()) {srtrue.pb(srch[0]);prev=srch[0].sn; continue;}
    if(srch[i].sn>=prev) continue;
    srtrue.pb(srch[i]); prev=srch[i].sn;
  }

  int k=rbtrue.size(), l = srtrue.size();
  vpi arr[k];
  prev=0;
  fr(i,0,k)
  {
    pi p1 = rbtrue[i];
    vpi diff;
    int tx=prev;
    int f=0;
    fr(j,tx,l)
    {
      pi p2 = srtrue[j];
      if(p2.fs<p1.fs) continue;
      else
      {
        if(!f)
        {
          pi ad2;
          ad2.sn = p2.sn-p1.sn+1;
          ad2.fs=0;
          diff.pb(ad2);
          f=1;
        }
        if(j==l-1 || srtrue[j+1].sn<p1.sn)
        {
          pi ad3;
          ad3.fs=p2.fs-p1.fs+1;
          ad3.sn=0;
          diff.pb(ad3);
          break;
        }
        pi addn;
        addn.fs=p2.fs-p1.fs+1;
        addn.sn=srtrue[j+1].sn-p1.sn+1;
        diff.pb(addn);
        // cout << "( " <<p2.fs << ", " << p2.sn << "), p2\n";
        // cout << "( " <<addn.fs << ", " << addn.sn << "), bruh\n";

      }
    }
    arr[i]=diff;
  }
  fr(i,0,k)
  {
    cout << "( " <<rbtrue[i].fs << ", " << rbtrue[i].sn << "): ";
    for(auto p: arr[i]) cout << "( " <<p.fs << ", " << p.sn << "), "; cout << endl;
  }
}
