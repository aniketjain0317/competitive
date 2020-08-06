// Problem
// Complete

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x+1 << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 1000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define bd(a,b,adj) adj[a].pb(b); adj[b].pb(a);
#define ud(a,b,adj) adj[a].pb(b);



bool visited[N]={};
vi adj [N];
int nbs[N]={};

vi treeCenters(int n, vi adj[N]);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  fr(i,0,n-1)
  {
    int a,b; cin >> a >> b;
    bd(a-1,b-1,adj);
    nbs[a-1]++; nbs[b-1]++;
  }
  vi leaves = treeCenters(n,adj);
  cnl(leaves[0]);
  if(leaves.size()==2) cnl(leaves[1]);
}

vi treeCenters(int n, vi adj[N])
{
  vi leaves;
  fr(i,0,n) if(nbs[i]==1) leaves.pb(i);
  int count = leaves.size();
  while(count<n)
  {
    for(auto x: leaves) {for(auto y: adj[x]) nbs[y]--; nbs[x]=-1;}
    leaves.clear();
    fr(i,0,n) if(nbs[i]==1) leaves.pb(i);
    if(leaves.empty()) fr(i,0,n) if(nbs[i]==0) leaves.pb(i);
    count+=leaves.size();
    // show1d(n,nbs);
  }
  return leaves;
}
