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
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int long long
#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mm(res, a);
        a = mm(a,a);
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a)
{
  return binpow(a,INF-2);
}


intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n,m; cin >> n >> m;
    char mat[n+1][m+1];
    fr(i,0,n) fr(j,0,m) cin >> mat[i+1][j+1];
    int xp,yp,p;
    cin >> xp >> yp;
    p = mm(xp,modInverse(yp));
    vpi src, dst, blc, db;
    frr(i,1,n) frr(j,1,m)
    {
      pi pp(i,j);
      if(mat[i][j]=='1') src.pb(pp);
      if(mat[i][j]=='x') blc.pb(pp);
      if(mat[i][j]=='2') dst.pb(pp);
    }
    int ans = 0;
    for(auto s: src)
    {
      int prob[n+1][m+1]={};
      int sx = s.fs, sy = s.sn;
      prob[sx][sy] = 1;
      int dp=0, bp=0;
      frr(i,sx,n)
      {
        frr(j,sy,m)
        {
          if(mat[i][j-1]=='.' || mat[i][j-1]=='1') prob[i][j]=mm(prob[i][j-1],p);
          if(mat[i-1][j]=='.' || mat[i-1][j]=='1') prob[i][j]=mm(prob[i-1][j],am(1,-p));

          if(mat[i][j]=='x') bp=am(bp, prob[i][j]);
        }
      }
      show2d(n+1,m+1,prob);
      for(auto d: dst)
      {
          int dx = d.fs, dy = d.sn;
          int dfp = mm(prob[dx][dy], modInverse(am(1,-bp)));
          int exp = mm(dfp,dx-sx+dy-sy);
          ans =am(ans,exp);
      }
    }
    cnl(ans);
  }
}
