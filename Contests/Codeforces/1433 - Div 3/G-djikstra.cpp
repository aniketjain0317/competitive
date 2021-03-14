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

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define bd(a,b,c,adj) adj[a-1].pb(mp(c,b-1)); adj[b-1].pb(mp(c,a-1));
#define ud(a,b,c,adj) adj[a-1].pb(mp(c,b-1));

const int INF = 1000000000;
int mat[1001][1001]={};
vector<vpi> adj;
vi dist;

void dijkstra(int s)
{
   priority_queue<pi,vpi,greater<pi>> pq;
   pq.push(mp(0,s));
   // fr(i,0,n) dist[i]=INF;
   dist[s]=0;
   while(!pq.empty())
   {
     pi node=pq.top();
     pq.pop();
     for(auto child: adj[node.sn])
     {
       int v=child.sn;
       int nwt = dist[node.sn]+child.fs;
       if(dist[v]>nwt)
       {
         dist[v]=nwt;
         pq.push(mp(dist[v],v));
       }
     }
   }
}
int getDist(int a, int b)
{
  if(a>b) return mat[b][a];
  if(a<b) return mat[a][b];
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m,k; cin >> n >> m >> k;
  adj.resize(n);
  vector<int> edges[m];
  fr(i,0,m)
  {
    int x,y,w; cin >> x >>  y>> w;
    bd(x,y,w,adj);
    edges[i].pb(x-1);
    edges[i].pb(y-1);
    edges[i].pb(w);
  }
  vpi couriers;
  fr(i,0,k)
  {
    int x,y;
    cin >> x >> y;
    pi p=mp(x-1,y-1);
    couriers.pb(p);
  }

  dist.resize(n,INF);
  fr(i,0,n)
  {
    fr(i,0,n) dist[i]=INF;
    dijkstra(i);
    fr(j,0,n) mat[i][j]=dist[j];
  }

  // show2d(n,n,mat);

  int mn=INF;
  fr(i,0,m)
  {
    int ans=0;
    int a = edges[i][0];
    int b = edges[i][1];
    fr(j,0,k)
    {
      int x = min(couriers[j].fs,couriers[j].sn);
      int y = max(couriers[j].fs,couriers[j].sn);
      int distance = getDist(x,y);
      if(getDist(x,a)+getDist(y,b)<distance) distance=getDist(x,a)+getDist(y,b);
      if(getDist(x,b)+getDist(y,a)<distance) distance=getDist(x,b)+getDist(y,a);
      ans+=distance;
    }
    if(mn>ans) {mn=ans;}
  }
  cnl(mn);
}
