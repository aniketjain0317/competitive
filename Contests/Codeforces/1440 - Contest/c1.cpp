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

int n=0,m=0,k = 0;
int mat[1000][1000]={};
vi ans[3 *1000*1000];

void solve(int x, int y, int cz)
{
  int xa[4]={x,x,x+1,x+1};
  int ya[4]={y,y+1,y,y+1};
  int cnt = 0;
  fr(i,0,4) cnt+= mat[xa[i]][ya[i]];
  if(cz!=-1 && cnt!=cz) return;
  // cnl("A "<<x<<" "<<y << " "<< cnt);
  if(cnt==0) return;
  if(cnt==1)
  {
    int i[3] ={};
    fr(j,0,4) if(mat[xa[j]][ya[j]]) i[0]=j;
    i[1] = (i[0]+1)%4; i[2] = (i[0]+2)%4;
    vi nxt;
    fr(j,0,3) {nxt.pb(xa[i[j]]); nxt.pb(ya[i[j]]);}
    ans[k++]=nxt;
    fr(j,0,3) mat[xa[i[j]]][ya[i[j]]]=!mat[xa[i[j]]][ya[i[j]]];
    solve(x,y,-1);
    return;
  }
  if(cnt==2)
  {
    int f[3]={}; int ch=0;
    fr(i,0,4)
    {
      if(mat[xa[i]][ya[i]]==0) f[ch++]=i;
      else f[2]=i;
    }
    vi nxt;
    fr(j,0,3) {nxt.pb(xa[f[j]]); nxt.pb(ya[f[j]]);}
    fr(j,0,3) mat[xa[f[j]]][ya[f[j]]]=!mat[xa[f[j]]][ya[f[j]]];

    ans[k++]=nxt;
    solve(x,y,-1);
    return;
  }
  if(cnt==3)
  {
    int f[3]={}; int ch=0;
    fr(i,0,4) if(mat[xa[i]][ya[i]]) f[ch++]=i;

    vi nxt;
    fr(j,0,3) {nxt.pb(xa[f[j]]); nxt.pb(ya[f[j]]);}
    fr(j,0,3) mat[xa[f[j]]][ya[f[j]]]=!mat[xa[f[j]]][ya[f[j]]];
    ans[k++]=nxt;
    return;
  }
  if(cnt==4)
  {
    int f[3]={1,2,3};
    vi nxt;
    fr(j,0,3) {nxt.pb(xa[f[j]]); nxt.pb(ya[f[j]]);}
    fr(j,0,3) mat[xa[f[j]]][ya[f[j]]]=!mat[xa[f[j]]][ya[f[j]]];
    ans[k++]=nxt;
    solve(x,y,-1);
    return;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {



    cin >> n >> m;
    fr(i,0,n) fr(j,0,m) {char c; cin >> c; mat[i][j] = (c=='1');}


    // for(int i =0; i<n-1; i+=2 )
    // {
    //   for(int  j=0; j<m-1; j+=2 )
    //   {
    //     solve(i,j);
    //   }
    // }
    //
    // if(m%2==1) for(int i=0;i<n-1;i+=2) solve(i,m-2);
    // if(n%2==1) for(int i=0;i<m-1;i+=2) solve(n-2,i);

    fr(i,0,n-1) fr(j,0,m-1) solve(i,j,3);
    fr(i,0,n-1) fr(j,0,m-1) solve(i,j,2);
    fr(i,0,n-1) fr(j,0,m-1) solve(i,j,1);
    fr(i,0,n-1) fr(j,0,m-1) solve(i,j,4);
    fr(i,0,n-1) fr(j,0,m-1) solve(i,j,-1);


    cnl(k);
    fr(i,0,k)
    {
      fr(j,0,6) csp(ans[i][j]+1); cout << endl;
    }
    // show2d(n,m,mat);
    fr(i,0,k) ans[i].clear();
    fr(i,0,n) fr(j,0,m) mat[i][j]=0;
    n=0; m =0; k=0;
  }

  // mat[0][0]=0; mat[0][1]=1;
  // mat[1][0]=1; mat[1][1]=0;
  // solve(0,0);
  // cnl(k);
  // fr(i,0,k)
  // {
  //   fr(j,0,6) csp(ans[i][j]); cout << endl;
  // }
}
