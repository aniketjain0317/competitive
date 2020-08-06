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
#define N 1000
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
#define vshow2d(arr) {int n=7;   fr(i,0,n) {int m = arr[i].size();csp(i+1<<":"); fr(j,0,m) csp(arr[i][j]+1); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;


#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a-1].pb(b-1);

vi tree[N];
int visited[N]={};
vi adj[N];
vi path;
vi depth;
int last[N]={};
int cn=0;
void visit(int,int);
void dfs(int,int);
int rmq(int l, int r);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int n,root; cin >> n >> root;
  fr(i,0,n-1) {int a,b; cin >> a >> b; ud(a,b,tree); bd(a,b,adj);}
  int x,y; cin >> x >> y;
  x--; y--; root--;

  dfs(root,0);
  int xi = min(last[x],last[y]), yi = max(last[x],last[y]);
  cnl(rmq(xi,yi)+1);
};

void dfs(int node, int nd)
{
  visit(node,nd);
  for(auto child: tree[node])
  {
    dfs(child,nd+1);
    visit(node,nd+1);
  }
}

void visit(int node, int nd)
{
  path.pb(node);
  depth.pb(nd);
  last[node]=cn;
  cn++;
}

int rmq(int l, int r)
{
  int mini=-1;
  frr(i,l,r)
  {
    if(mini==-1 || depth[mini]>depth[i]) mini=i;
  }
  return path[mini];
}
