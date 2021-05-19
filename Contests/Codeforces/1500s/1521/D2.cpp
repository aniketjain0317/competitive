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
const int N = 100005;

int n=0;
vi adj2[N];
vi adj[N];


bool visited[N]={};

void clearAll()

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
  for(auto &child:adj[node]) mxs(val[node], val[child]+1);
  sort(all(adj[node]), [](int a, int b) {return val[a]>val[b];});
}

vvi join;
deque<vi> del;
int qd[N]={};
int curr=-1;
int f=-1;

void addTree(int node)
{
  int sz = adj[node].size();
  fr(i,0,sz)
  {
    int child = adj[node][i];
    if(i>qd[node])
    {
      del.pb({child,node});
      qd[child]=1;
    }
    addTree(child);
  }

  if(adj[node].size()==0)
  {
    if(f==1) join.pb({node,curr}), f--;
    else f++;
    curr=node;
  }
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
    fr(i,0,n-1)
    {
      int a,b; cin >> a >> b;
      adj2[a].pb(b);
      adj2[b].pb(a);
    }
    rootTree(1);
    calcVal(1);
    qd[1]=1;
    addTree(1);
    cnl("AAAAAA");
    showVVI(del);
    cnl("AAA");
    showVVI(join);
  }
}
