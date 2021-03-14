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
#define N 1001

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a-1].pb(b-1);



vi adj[N];
vi act;

ll pr = 1e9+7;
ll power(ll x, int y, ll p)
{
    ll res = 1;     // Initialize result

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


void dfs(int);
int bfs(int);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  test(t)
  {
    int n; cin >> n;
    fr(i,0,n) adj[i].clear();
    fr(i,0,n-1)
    {
      int u,v; cin >> u >> v;
      bd(u,v,adj);
    }
    act.clear();
    act.resize(n,0);
    fr(i,0,n)
    {
      int x; cin >> x;
      if(x%2) {act[i]=1; }
    }
    ll ans=0;
    fr(i,0,n)
    {
      int x = bfs(i);
      if(!x)
      {
        ll a = power(2,i+1,pr);
        if(a<0) a=(a+pr)%pr;
        ans = (ans+a)%pr;
      }
    }
    cnl(ans);
  }
}


// void dfs(int node)
// {
//   visited[node]=1;
//
//   for(auto child: adj[node])
//   {
//     if(!visited[child])
//     {
//       dfs(child);
//     }
//   }
// }

int bfs(int first)
{
  int ans=0;
  bool visited[N]={};
  int dist[N]={};
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
        if(act[child]) {ans=ans^dist[child];}
        q.push(child);
        visited[child]=1;
      }
    }
    q.pop();
  }
  return ans;
}
