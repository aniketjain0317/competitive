// Playlist video 5 (bfs) - shortest path
// Complete

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
#define endl '\n'
#define intt int32_t
// #define int long long

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

class Grid
{
public:
  int n,m;
  vpi dir;
  int sz;

  map<pi,bool> walls;
  bool used_walls=0;

  map<pi,bool> visited;
  map<pi,pi> parent;

  Grid(int fn, int fm, vpi fdir)
  {
    n=fn;
    m=fm;
    dir=fdir;
    sz=dir.size();
  }

  void addWalls(vpi fwalls)
  {
    used_walls=1;
    for(pi p: fwalls) walls[p]=1;
  }

  vpi neighbors(pi p)
  {
    vpi ans;
    for(pi d: dir)
    {
      pi nx(p.fs+d.fs,p.sn-d.sn);
      if(nx.fs<0 || nx.fs>=n) continue;
      if(nx.sn<0 || nx.sn>=m) continue;
      if(used_walls && walls[nx]==1) continue;
      ans.pb(nx);
    }
    return ans;
  }

  void bfs(pi first)
  {
    visited[first]=1;
    parent[first]=mp(-1,-1);
    queue<pi> q;
    q.push(first);
    while(!q.empty())
    {
      pi node = q.front();
      for(auto child: neighbors(node))
      {
        if(!visited[child])
        {
          q.push(child);
          visited[child]=1;
          parent[child]=node;
        }
      }
      q.pop();
    }
  }

  vpi findShortestPath(pi start, pi end)
  {
    bfs(start);
    vpi result;
    pi node = end;
    if(parent.find(node)==parent.end()) return result;
    while(node!=mp(-1,-1))
    {
      result.pb(node);
      node=parent[node];
      csp("AAAAA");
      csp(node.fs);
      cnl(node.sn);
    }
    reverse(all(result));
    if(result[0]!=start) result.clear();
    return result;
  }
};


int main()
{
  int n,m;
  cin >> n >> m;
  pi s,e;
  vpi dir({{1,0},{0,1},{-1,0},{0,-1}});
  char arr[n][m];
  vpi fwalls;
  fr(i,0,n) fr(j,0,m)
  {
    cin >> arr[i][j];
    if(arr[i][j]=='S') s=mp(i,j);
    if(arr[i][j]=='E') e=mp(i,j);
    if(arr[i][j]=='#') fwalls.pb(mp(i,j));
  }

  Grid grid(n,m,dir);
  grid.addWalls(fwalls);

  vpi ans = grid.findShortestPath(s,e);

  if(ans.empty()) cnl("NOT CONNECTED");
  else
  {
    for(auto p: ans)
    {
      csp(p.fs+1); cnl(p.sn+1);
    }
  }
}
 

// void bfs(Point root)
// {
//   visited[root.x][root.y]=1;
//   queue<Point> q;
//   q.push(root);
//   while(!q.empty())
//   {
//     Point node = q.front();
//     vpi nbs = neighbors(node);
//     for(auto child: nbs)
//     {
//       if(!visited[child.x][child.y] && arr[child.x][child.y]!='#')
//       {
//         q.push(child);
//         // csp(child.x); cnl(child.y);
//         visited[child.x][child.y]++; //this is neccessary here and not after node decl because 2 sister nodes can have same child
//         parent[child.x][child.y]=node;
//       }
//     }
//     q.pop();
//   }
// }
//
// vpi findPath(Point start, Point end)
// {
//   vpi result;
//   Point node = parent[end.x][end.y]; int flag = 0;
//
//   result.pb(end);
//   while(true)
//   {
//     if(node.x==-1) {flag=-1; break;}
//     result.pb(node);
//     if(node==start) {flag=1; break;}
//     node = parent[node.x][node.y];
//   }
//
//   reverse(result.begin(), result.end());
//   if(flag==-1) result.clear();
//   return result;
// }
//
// vpi neighbors(Point p)
// {
//   vpi ans;
//   fr(i,0,4)
//   {
//     Point q = p+dv[i];
//     if(q.x<0 || q.y<0 || q.x >= n || q.y >=m) continue;
//     ans.pb(q);
//   }
//   return ans;
// }
