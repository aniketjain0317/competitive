// Playlist video 5 (bfs) - shortest path
// Complete

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define csp(x) cout << x << " "
#define cnl(x) cout << x << endl
#define fr(a,b,c) for(int a = b; a<c; a++)
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]+1);}cout<<endl;
#define N 1000
typedef vector<int> vi;

struct Point
{
  int x,y;
};
Point operator+(const Point& lhs, const Point& rhs)
{
  Point c;
  c.x = lhs.x + rhs.x;
  c.y = lhs.y + rhs.y;
  return c;
};
bool operator==(const Point& lhs, const Point& rhs)
{
    return lhs.x==rhs.x && lhs.y == rhs.y;
};
typedef vector<Point> vpi;

int visited[N][N]={};
Point parent[N][N]={};
char arr[N][N]={};
int n,m;
Point dv[4]={{-1,0},{1,0},{0,-1},{0,1}};

void bfs(Point root);
vpi findPath(Point start, Point end);
vpi neighbors(Point p);

int main()
{
  cin >> n >> m;
  Point s,e;
  fr(i,0,n) fr(j,0,m)
  {
    cin >> arr[i][j];
    if(arr[i][j]=='S') {s.x=i;s.y=j;}
    if(arr[i][j]=='E') {e.x=i;e.y=j;}
  }
  fr(i,0,n) fr(j,0,m) parent[i][j]={-1,-1};
  bfs(s);


  vpi ans = findPath(s,e);

  if(ans.empty()) cnl("NOT CONNECTED");
  else
  {
    for(auto p: ans)
    {
      csp(p.x+1); cnl(p.y+1);
    }
  }
}


void bfs(Point root)
{
  visited[root.x][root.y]=1;
  queue<Point> q;
  q.push(root);
  while(!q.empty())
  {
    Point node = q.front();
    vpi nbs = neighbors(node);
    for(auto child: nbs)
    {
      if(!visited[child.x][child.y] && arr[child.x][child.y]!='#')
      {
        q.push(child);
        // csp(child.x); cnl(child.y);
        visited[child.x][child.y]++; //this is neccessary here and not after node decl because 2 sister nodes can have same child
        parent[child.x][child.y]=node;
      }
    }
    q.pop();
  }
}

vpi findPath(Point start, Point end)
{
  vpi result;
  Point node = parent[end.x][end.y]; int flag = 0;

  result.pb(end);
  while(true)
  {
    if(node.x==-1) {flag=-1; break;}
    result.pb(node);
    if(node==start) {flag=1; break;}
    node = parent[node.x][node.y];
  }

  reverse(result.begin(), result.end());
  if(flag==-1) result.clear();
  return result;
}

vpi neighbors(Point p)
{
  vpi ans;
  fr(i,0,4)
  {
    Point q = p+dv[i];
    if(q.x<0 || q.y<0 || q.x >= n || q.y >=m) continue;
    ans.pb(q);
  }
  return ans;
}
