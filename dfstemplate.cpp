// Problem
//

#include <bits/stdc++.h>
using namespace std;
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
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 1000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a-1].pb(b-1);



bool visited[N]={};
vi adj [N];
int dist[N];

void dfs(int);
void bfs(int);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

}


void dfs(int node)
{
  visited[node]=1;
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}

void bfs(int first)
{
  queue<int> q;
  visited[first]=1;
  q.push(first);
  while(!q.empty())
  {
    int node = q.front();
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        dist[child]=dist[node]+1;
        q.push(child);
        visited[child]=1;
      }
    }
    q.pop();
  }
}
