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

int xxx=0;
int pr = 1e9+7;
ll power(int x, ll y, ll p)
{
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int dfs(int node, vi adj[], int arr[],int visited[], vi p);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  test(t)
  {
    xxx=0;
    int n; cin >> n;
    vi adj[n];
    ll ans=0;
    fr(i,0,n-1)
    {
      int u,v; cin >> u >> v;
      u--; v--;
      adj[u].pb(v); adj[v].pb(u);
    }
    int arr[n]={};
    fr(i,0,n)
    {
      int a; cin >> a;
      if(a%2) arr[i]=1;
    }
    fr(i,0,n)
    {
      xxx=0;
      vi p(n,0);
      int visited[n]={};
      int a = dfs(i,adj,arr,visited,p);
      if(!a)
      {
        ll md = power(2,i+1,pr);
        if(md<0) md+=pr;
        ans=(ans+md)%pr;
      }
    }
    cnl(ans);
  }
}

int dfs(int node, vi adj[], int arr[],int visited[], vi p)
{
  visited[node]=1;
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      p[child]=p[node]+1;
      if(arr[child]) xxx=xxx^p[child];
      dfs(child,adj,arr,visited,p);
    }
  }
  return xxx;
}
