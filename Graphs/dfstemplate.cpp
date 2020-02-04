#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define nl cout << endl
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define cinp(n,arr) forr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 100000000

#define bd(a,b,adj) adj[a].pb(b); adj[b].pb(a);
#define ud(a,b,adj) adj[a].pb(b);

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;


bool visited[N]={};
vi(graph)[N];


int main()
{

}

void dfs(int node)
{
  visited[node]=1;
  for(auto child: graph[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}
