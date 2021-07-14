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
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 200005;

int n=0;
vi adj2[N];
vi adj[N];
int parent[N]={};
int val[N]={};

bool visited[N]={};

void rootTree(int node)
{
  visited[node]=1;
  for(auto &child: adj2[node])
  {
    if(!visited[child])
    {
      parent[child] = node;
      adj[node].pb(child);
      rootTree(child);
    }
  }
}

void dfs(int node)
{
  for(auto &child: adj[node])
  {
    dfs(child);
    val[node]+=val[child];
  }
  // if(adj[node].empty()) val[node]=1;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    cin >> n;
    frr(i,0,n) adj2[i].clear();
    frr(i,0,n) adj[i].clear();
    frr(i,0,n) visited[i]=0;
    frr(i,0,n) parent[i]=-1;
    frr(i,0,n) val[i]=1;

    fr(i,0,n-1)
    {
      int u,v; cin >> u >> v;
      adj2[u].pb(v);
      adj2[v].pb(u);
    }

    rootTree(0);
    dfs(0);
    int ans[n+1]={};
    int used[n]={}; used[0]=1;
    int e[2]={}; e[1]=1;
    int flag = 0;
    // i == 0
    {
      for(auto &child: adj[0])
        ans[0] += (val[child]* (val[child]-1))/2;
    }

    // i == 1
    {
      int x = 1, p;
      while(x!=0)
      {
        used[x]=1;
        if(parent[x]==0) p=x;
        x = parent[x];
      }
      val[0]-=val[p];
      ans[1]+=val[0]*(val[p]-val[1]);
      int vz = val[0];
      for(auto &child: adj[0])
      {
        if(child==p) continue;
        int a = val[child];
        vz -= a;
        ans[1]+=a*vz;
      }
    }

    fr(i,2,n)
    {
      if(used[i]) {ans[i]=0; continue;}
      int x = i, m = -1;
      while(!used[x]) used[x]=1, x = parent[x];
      if(e[0]==x) m=0;
      if(e[1]==x) m=1;
      if(m==-1)
      {
        ans[i] =val[e[0]]*val[e[1]];
        flag = 1; break;
      }
      ans[i] = (val[e[m]] - val[i]) * val[e[!m]];
      e[m]=i;
    }

    // i==n
    if(!flag) ans[n] = 1;

    show1d(n+1,ans);
  }
}

// 0
// 1 2 3
