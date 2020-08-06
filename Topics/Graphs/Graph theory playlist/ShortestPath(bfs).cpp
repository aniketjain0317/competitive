// Playlist video 5 (bfs) - shortest path
// Complete

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define csp(x) cout << x << " "
#define cnl(x) cout << x << endl
#define fr(a,b,c) for(int a = b; a<c; a++)
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]+1);}cout<<endl;
#define N 100000
typedef vector<int> vi;

vi adj[N];
int visited[N]={};
int parent[N]={};

void bfs(int root);
vi findPath(int start, int end);

int main()
{
  int n,m; cin >> n >> m;
  fr(i,0,m)
  {
    int a,b; cin >> a >> b;
    adj[a-1].pb(b-1);
    adj[b-1].pb(a-1);
  }
  int s,e; cin >> s >> e;

  fr(i,0,n) parent[i]=-1;

  bfs(s-1);
  vi ans = findPath(s-1,e-1);
  if(ans.empty()) cnl("NOT CONNECTED");
  else show1d(ans.size(),ans);
}


void bfs(int root)
{
  visited[root]=1;
  queue<int> q;
  q.push(root);
  while(!q.empty())
  {
    int node = q.front();
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        q.push(child);
        visited[child]++; //this is neccessary here and not after node decl because 2 sister nodes can have same child
        parent[child]=node;
      }
    }
    q.pop();
  }
}

vi findPath(int start, int end)
{
  vi result;
  int node = parent[end], flag = 0;
  result.pb(end);
  while(true)
  {
    if(node==-1) {flag=-1; break;}
    result.pb(node);
    if(node==start) {flag=1; break;}
    node = parent[node];
  }

  reverse(result.begin(), result.end());
  if(flag==-1) result.clear();
  return result;
}
