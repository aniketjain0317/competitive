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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define showpair(p) csp("("<<p.fs+1<<","<<p.sn+1<<")")
#define N 100001

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef stack<pi> spi;
typedef vector<spi> vspi;
#define bd(a,b,adj) adj[a].pb(b); adj[b].pb(a);
#define ud(a,b,adj) adj[a].pb(b);



bool visited[N]={};
vi adj [N];
int dist[N];

int x=-1;
vi nets;
vpi ans;
vspi redundant;

void dfs(int);
void bfs(int);

vi pairsort(vi a, vi b, int n)
{
    pair<int, int> pairt[n];
    // cnl("A");
    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = i;
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);
    reverse(pairt,pairt+n);
    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
    return b;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // vi a; a.pb(10); a.pb(5); a.pb(15);
  // vi b; b.pb(10); b.pb(5); b.pb(15);
  // pairsort(a,b,3);
  // show1d(3,a);
  // show1d(3,b);
  test(t)
  {
    int n,m; cin >> n >> m;
    fr(i,0,m)
    {
      int a; int b; cin >> a >> b;

      if(a<b) adj[a-1].pb(b-1);
      if(b<a) adj[b-1].pb(a-1);
    }
    fr(i,0,n)
    {
      if(!visited[i])
      {
        x++;
        nets.pb(0);
        spi empty; pi t1(i,-1);
        empty.push(t1);
        redundant.pb(empty);
        dfs(i);
      }
    }
    vi ord(x+1);
    fr(i,0,x+1) ord[i]=i;
    ord = pairsort(nets,ord,x+1);
    int cs=0;

    // show1d(x+1,ord);
    frr(i,1,x)
    {
      pi one = redundant[ord[cs]].top();
      pi two = redundant[ord[i]].top();
      pi p(one.fs,two.fs);
      ans.pb(p);
      if(one.sn!=-1) redundant[ord[cs]].pop();
      else cs++;
      if(two.sn!=-1) redundant[ord[i]].pop();
    }
    for(auto st: redundant)
    {
      while(st.size()>1)
      {
        ans.pb(st.top());
        st.pop();
      }
    }
    cnl(ans.size());
    for(auto p: ans) {cnl(p.fs+1 << " " <<p.sn+1);}
    fr(i,0,n)
    {
      adj[i].clear();
      visited[i]=0;
    }
    x=-1;
    ans.clear();
    redundant.clear();
    nets.clear();
  }
}


void dfs(int node)
{
  visited[node]=1;
  for(auto child: adj[node])
  {
    pi p; p.fs = node; p.sn = child;
    if(!visited[child])
    {
      dfs(child);
      ans.pb(p);
    }
    else
    {
      nets[x]++;
      redundant[x].push(p);
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
