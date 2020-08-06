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
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int nx[8]={0,1,1,1,0,-1,-1,-1};
int ny[8]={1,1,0,-1,-1,-1,0,1};
int h=0,h2=0;
int comp[200][200]={};
int last=1;
vi ans;

void dfs(int x, int y, int c, int mat[200][200]);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("../myans.txt","w",stdout);
  freopen("../input.txt","r",stdin);
  while(true)
  {
    int w; cin >> h >> w;
    if(h==0) break;
    h2=4*w;
    int mat[200][200]={};
    ans.pb(0);
    fr(i,0,h) fr(j,0,w)
    {
      char t; cin >> t;
      if(t<58)
      {
        int t2 = t-48;
        mat[i][4*j+3]=t2%2;
        t2/=2;
        mat[i][4*j+2]=t2%2;
        t2/=2;
        mat[i][4*j+1]=t2%2;
        t2/=2;
        mat[i][4*j]=t2%2;
      }
      else
      {
        int t2 = t-87;
        mat[i][4*j+3]=t2%2;
        t2/=2;
        mat[i][4*j+2]=t2%2;
        t2/=2;
        mat[i][4*j+1]=t2%2;
        t2/=2;
        mat[i][4*j]=t2%2;
      }
    }
    show2d(h,h2,mat);

    dfs(0,0,1,mat);
    cnl("TEST");
    vshow1d(ans);

    h=0; h2=0;
    fr(i,0,h) fr(j,0,h2) comp[i][j]=0;
    last=0;
    ans.clear();
  }
}

void dfs(int x, int y, int c, int mat[200][200])
{
  cnl(x<<" "<<y<<" "<<c);
  int px=mat[x][y];
  comp[x][y]=c;
  if(px)
  {
    fr(i,0,8)
    {
      int x1=x+nx[i], y1=y+ny[i];
      if(x1<0 || y1<0 || x1>=h || y1>=h2) continue;
      if(!comp[x1][y1] && mat[x1][y1])
      {
        dfs(x1,y1,c,mat);
      }
    }
    fr(i,0,8)
    {
      int x1=x+nx[i], y1=y+ny[i];
      if(x1<0 || y1<0 || x1>=h || y1>=h2) continue;
      if(!comp[x1][y1] && !mat[x1][y1])
      {
        ans[c]++;
        dfs(x1,y1,c,mat);
      }
    }
  }

  if(!px)
  {
    fr(i,0,8)
    {
      int x1=x+nx[i], y1=y+ny[i];
      if(x1<0 || y1<0 || x1>=h || y1>=h2) continue;
      if(!comp[x1][y1] && !mat[x1][y1])
      {
        dfs(x1,y1,c,mat);
      }
    }
    fr(i,0,8)
    {
      int x1=x+nx[i], y1=y+ny[i];
      if(x1<0 || y1<0 || x1>=h || y1>=h2) continue;
      if(!comp[x1][y1] && mat[x1][y1])
      {
        {ans.pb(0);last+=1; dfs(x1,y1,last,mat);}
      }
    }
  }
}
