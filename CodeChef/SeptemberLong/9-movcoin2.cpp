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
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  // test(t)
  {
    int n; n=20;
    // vi adj[n];
    // fr(i,0,n-1)
    // {
    //   int u=i;
    //   int v=i+1;
    //   adj[u].pb(v);
    //   adj[v].pb(u);
    // }
    // int box[n]={};
    // fr(i,0,n)
    // {
    //   if(i==4||i==11||i==15)
    //   {
    //     box[i]=1;
    //   }
    // }
    // int gm[3]={4,11,15};
    // int r=0;
    map<multiset<int> ,int> dp;
    dp[{0,0,0,0}]=2;
    fr(i,0,n) fr(j,i,n) fr(k,j,n) fr(u,k,n)
    {
      int ch=-1, ch2=-1;
      fr(l,0,i) if(dp[{l,j,k,u}]==2) {ch=l; ch2=1; dp[{i,j,k,u}]=1; break;}
      fr(l,0,j) if(dp[{l,i,k,u}]==2) {ch=l; ch2=2; dp[{i,j,k,u}]=1; break;}
      fr(l,0,k) if(dp[{i,j,l,u}]==2) {ch=l; ch2=3; dp[{i,j,k,u}]=1; break;}
      fr(l,0,u) if(dp[{i,j,k,l}]==2) {ch=l; ch2=3; dp[{i,j,k,u}]=1; break;}

      // cnl(flag << i << j << k);

      if(ch2==-1) dp[{i,j,k,u}]=2;
    }
    fr(i,0,n)
    {
      cnl("I << " << i);
      csp(i<<" ");
      fr(k,0,n) csp(k);
      cout << endl << endl;
      fr(j,i,n)
      {
        csp(j<<" ");
        fr(k,0,j) cout << "0 ";
        fr(k,j,n) cout << dp[{1,i,j,k}] << " ";
        cout << endl; 
      }
    }
    cout << "ANS " << dp[{4,11,11}];
  }
}
