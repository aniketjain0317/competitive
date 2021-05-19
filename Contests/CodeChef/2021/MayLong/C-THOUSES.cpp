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
#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 300005;

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}

vi adj[N];
vi adj2[N];
bool visited[N]={};

void rootTree(int node)
{
  visited[node]=1;
  for(auto &child: adj2[node])
  {
    if(!visited[child])
    {
      adj[node].pb(child);
      rootTree(child);
    }
  }
}

vi val(N,1);
void calcVal(int node)
{
  for(auto &child: adj[node]) calcVal(child);
  sort(all(adj[node]), [](int a, int b) {return val[a]>val[b];});
  int curr=1;
  for(auto &child: adj[node]) val[node]+=(curr++)*val[child];
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
    int n,x; cin >> n >> x;
    frr(i,0,n) adj2[i].clear();
    frr(i,0,n) adj[i].clear();
    frr(i,0,n) visited[i]=0;
    val.clear();
    val.resize(n+1,1);
    fr(i,0,n-1)
    {
      int u,v; cin >> u >> v;
      adj2[u].pb(v); adj2[v].pb(u);
    }
    rootTree(1);
    calcVal(1);
    cnl(mm(x,val[1]));
  }
}
