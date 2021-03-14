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
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n,q; cin >> n >> q;
    ll arr[n]; cinp(n,arr);
    set<pi> intervals;
    int a=0, c=0;
    fr(i,1,n)
    {
      if(arr[i]==arr[i-1])
      {
        if(c==0)
        {
          if(a>i-2) {c=1; continue;}
          pi p(a,i-2);
          intervals.insert(p);
          c=1;
        }
      }
      else
      {
        if(c==1) {a=i; c=0;}
        if(i==n-1)
        {
          pi p(a,i);
          intervals.insert(p);
        }
      }
    }
    fr(i,0,q)
    {
      int x; ll y; cin >> x >> y;
      pi sh(x,x);
      pi p = intervals.lower_bound(sh);
    }
    // int ch[n]={};
    // fr(i,0,n)
    // {
    //   int cs = 0;
    //   if(i>0) if(arr[i]==arr[i-1]) cs=1;
    //   if(i<n-1) if(arr[i]==arr[i+1]) cs=1;
    //   ch[i]=cs;
    // }
    // // for(auto p: intervals) {csp(p.fs); cnl(p.sn);}
    // fr(i,0,q)
    // {
    //   int x; ll y; cin >> x >> y;
    //   int cs = 0;
    //   if(x>0)
    //   {
    //     if(y==arr[x-1]) {ch[x]=1; ch[x-1]=1;cs=1;}
    //     else if(arr[x]==arr[x-1])
    //     {
    //       if(x==1 || arr[x-1]!=arr[x-2]) {ch[x]=0; ch[x-1]=0;}
    //     }
    //   }
    //   if(x<n-1)
    //   {
    //     if(y==arr[x+1]) {ch[x]=1; ch[x+1]=1;cs=1;}
    //     else if(arr[x]==arr[x+1])
    //     {
    //       if(x==n-2 || arr[x+1]!=arr[x+2]) {ch[x]=0; ch[x-1]=0;}
    //     }
    //   }
    //   ch[x]=cs;
    //   arr[x]=y;
    // }
    // int mxlen=0;
    // int currlen=0;
    // fr(i,0,n)
    // {
    //   if(!ch[i]) currlen++;
    //   if(mxlen<currlen) mxlen=currlen;
    //   if(ch[i]) currlen=0;
    // }
    // cnl(mxlen);
  }
}
