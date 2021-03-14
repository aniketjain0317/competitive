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

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

vi adj[N];
int visited[N]={};
int cycles=0;
int flag=0;

void dfs(int node, int parent);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    fr(i,0,N)
    {
      adj[i].clear();
      visited[i]=0;
      cycles=0;
      flag=0;
    }
    int n,m; cin >> n >>  m;
    pi rooks[m];
    fr(i,0,m) cin >> rooks[i].fs >> rooks[i].sn;
    int xpos[n+1]={}, ypos[n+1]={};
    int p = m;
    fr(i,0,m)
    {
      pi r = rooks[i];
      if(r.fs==r.sn) {p--; continue;}
      xpos[r.fs]=(i+1);
      ypos[r.sn]=(i+1);
    }
    frr(i,1,n)
    {
      if(xpos[i] && ypos[i])
      {
        // cnl("FSJKB FJLKF "<<i);
        adj[xpos[i]].pb(ypos[i]);
        adj[ypos[i]].pb(xpos[i]);
      }
    }
    // cnl("ADJ S");
    // fr(i,1,n+1)
    // {
    //   for(auto x: adj[i]) csp(x);
    //   cout << endl;
    // }
    // cnl("ADJ E");
    // fr(i,1,n+1)
    // {
    //   if(xpos[i].size()==2)
    //   {
    //     adj[xpos[i][0]].pb(xpos[i][1]);
    //     adj[xpos[i][1]].pb(xpos[i][0]);
    //   }
    //   if(ypos[i].size()==2)
    //   {
    //     adj[ypos[i][0]].pb(ypos[i][1]);
    //     adj[ypos[i][1]].pb(ypos[i][0]);
    //   }
    // }


    fr(i,1,m+1)
    {
      if(!visited[i]) dfs(i,-1);
      flag=0;
    }

    int ans = cycles + p;
    cnl(ans);
  }
}


void dfs(int node, int parent)
{
  visited[node]=1;
  for(auto child: adj[node])
  {
    if(child!=parent)
    {
      if(visited[child])
      {
        // cout << "ASFJBAF " << node << " " << child << endl;
        cycles++;
        flag=1;
        break;
      }
      dfs(child,node);
      if(flag) return;
    }
  }
}
