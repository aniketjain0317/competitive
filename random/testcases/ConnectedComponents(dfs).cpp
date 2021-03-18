// Playlist video 4 (dfs) - 5:15
// Complete

/*
  n - nodes
  m - edges
  a,b - edge between node a and node b

  component numbering starts from 1.
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define csp(x) cout << x << " ";
#define fr(a,b,c) for(int a = b; a<c; a++)
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define N 100000
typedef vector<int> vi;

vi adj[N];
int result[N]={};
bool visited[N]={};
int c=0;

void dfs(int node);
void connectedComponents(int n);


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("output8","w",stdout);
  freopen("input8","r",stdin);
  int n,m; cin >> n >> m;
  fr(i,0,m)
  {
    int a,b; cin >> a >> b;
    adj[a-1].pb(b-1);
    adj[b-1].pb(a-1);
  }

  connectedComponents(n);
  cout << c-1;
}

void connectedComponents(int n)
{
  fr(i,0,n)
  {
    if(!visited[i])
    {
      c++;
      dfs(i);
    }
  }
}

void dfs(int node)
{
  visited[node]=1;
  result[node]=c;
  for(auto child: adj[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}
