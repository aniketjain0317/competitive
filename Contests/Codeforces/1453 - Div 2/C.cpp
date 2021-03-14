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
#define all(v) v.begin(),v.end()
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
    int n; cin >> n;
    int arr[n][n]={};
    fr(i,0,n) fr(j,0,n)
    {
      char c; cin >> c;
      int d = c-'0';
      arr[i][j]=d;
    }
    vi rhigh(10,-1), rlow(10,-1), chigh(10,-1), clow(10,-1);
    fr(i,0,n) fr(j,0,n)
    {
      int d = arr[i][j];
      if(rhigh[d]==-1 || rhigh[d]<i) rhigh[d]=i;
      if(rlow[d]==-1 || rlow[d]>i) rlow[d]=i;
      if(chigh[d]==-1 || chigh[d]<j) chigh[d]=j;
      if(clow[d]==-1 || clow[d]>j) clow[d]=j;
    }
    vi ans(10,0);
    fr(d,0,10)
    {
      fr(i,0,n)
      {
        vi psn;
        int b=0,h=0;
        fr(j,0,n) if(arr[i][j]==d) psn.pb(j);
        if(psn.empty()) continue;
        for(auto k: psn)
        {
          b = max(k,n-k-1);
          h = max(abs(rhigh[d]-i), abs(rlow[d]-i));
          int ar = b*h;
          if(ar>ans[d]) ans[d]=ar;
        }
        if(psn.size()>1)
        {
          int k[2]={};
          k[0]=*min_element(all(psn));
          k[1]=*max_element(all(psn));
          int ar = (k[1]-k[0]) * max(i,n-i-1);
          if(ar>ans[d]) ans[d]=ar;
        }
      }
      fr(j,0,n)
      {
        vi psn;
        int b=0,h=0;
        fr(i,0,n) if(arr[i][j]==d) psn.pb(i);
        if(psn.empty()) continue;
        for(auto k: psn)
        {
          b = max(k,n-k-1);
          h = max(abs(chigh[d]-j), abs(clow[d]-j));
          int ar = b*h;
          if(ar>ans[d]) ans[d]=ar;
        }
        if(psn.size()>1)
        {
          int k[2]={};
          k[0]=*min_element(all(psn));
          k[1]=*max_element(all(psn));
          int ar = (k[1]-k[0]) * max(j,n-j-1);
          if(ar>ans[d]) ans[d]=ar;
        }
      }
    }
    show1d(10,ans);
  }
}
