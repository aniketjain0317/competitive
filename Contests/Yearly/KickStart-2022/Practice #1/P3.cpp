// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
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
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define cp2(x) (__builtin_popcountll(x)==1)
#define lp2(x) (__builtin_ctzll(x))
#define tc(tno) cout << "Case #" << tno << ": "
#define dsp(x) cout << #x << ": " << x << ", "
#define dnl(x) cout << #x << ": " << x << endl
#define cnlret(x) {cnl(x); return;}


template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T>             ostream& operator<<(ostream& os,  set<T>  v)   {os<<"{"; for (auto& i : v) os << i << ','; os<<"}"; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ':' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> bool chmin(T& a, U b){if (a > b) {a = b; return true;} return false;}
template<typename T, typename U> bool chmax(T& a, U b){if (a < b) {a = b; return true;} return false;}


#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1000000007;
const ll INF = 1LL<<62;
const int N = 100005;

int n, m;
vector<map<int,int>> flow;
vi visited;
int dfs(int node, vector<int> &path, int &source, int &sink)
{
  if(!path.empty() && path.back()==sink) return 1;
  path.push_back(node);
  visited[node]=1;
  if(node==sink) return 1;
  for(auto &p: flow[node])
  {
    int child = p.fs;
    int val = 1 - p.sn;
		if(node==source) val+=(INF-1);
    if((!visited[child]) && val)
      if(dfs(child, path, source, sink))
        return 1;
  }
  path.pop_back();
  return 0;
}

int fordFulkerson(int source, int sink)
{
	if(flow[source].empty() || flow[sink].empty()) return 0;
	for(auto &m: flow) for(auto &p: m) p.sn = 0;
	visited.clear(); visited.resize(m+4,0);
  vector<int> path;
  while(dfs(source, path, source, sink))
  {
    int val = INF;
    for(int i = 2; i<path.size(); i++)
		{
			val = min(val, 1 - flow[path[i-1]][path[i]]);
		}

    for(int i = 1; i<path.size(); i++)
    {
      flow[path[i-1]][path[i]] += val;
      flow[path[i]][path[i-1]] -= val;
    }
		visited.clear(); visited.resize(m+4,0);
    path.clear();
    dfs(source, path, source, sink);
		// dnl(flow);
  }
  int ans = 0;
  for(auto p: flow[source]) ans += p.second;
  return ans;
}


void solve()
{
  cin >> n;  m = n*n;
	vvi arr(n, vi(n, 0));
	flow.clear(); flow.resize(m+4);
  fr(i,0,n) fr(j,0,n)
  {
    char x; cin >> x;
    if(x=='R') arr[i][j]=1;
    if(x=='B') arr[i][j]=2;
  }
  vi cnt(3,0);
  fr(i,0,n) fr(j,0,n) cnt[arr[i][j]]++;
	if(abs(cnt[1]-cnt[2])>1) cnlret("Impossible");
	fr(i,0,n) fr(j,0,n) if(arr[i][j])
	{
		// csp(i), csp(j), cnl(i*n+j);
		if(i       && arr[i][j]==arr[i-1][j]) flow[i*n+j][(i-1)*n+j] = flow[(i-1)*n+j][i*n+j] = 0;
		if(j 			 && arr[i][j]==arr[i][j-1]) flow[i*n+j][i*n+j-1]   = flow[i*n+j-1][i*n+j]   = 0;
		if(i<(n-1) && arr[i][j]==arr[i+1][j]) flow[i*n+j][(i+1)*n+j] = flow[(i+1)*n+j][i*n+j] = 0;
		if(j<(n-1) && arr[i][j]==arr[i][j+1]) flow[i*n+j][i*n+j+1]   = flow[i*n+j+1][i*n+j]   = 0;
	}
	fr(j,0,n) if(arr[0][j]==1) flow[m][j] = flow[j][m] = 0;
	fr(i,0,n) if(arr[i][0]==2) flow[m+1][i*n] = flow[i*n][m+1] = 0;
	fr(j,0,n) if(arr[n-1][j]==1) flow[m+2][n*n-n+j] = flow[n*n-n+j][m+2] = 0;
	fr(i,0,n) if(arr[i][n-1]==2) flow[m+3][i*n+n-1] = flow[i*n+n-1][m+3] = 0;
	// m, m+2
	// m+1, m+3
	vi ch(2,0);
	ch[0] = fordFulkerson(m, m+2); ch[1] = fordFulkerson(m+1, m+3);
	if(ch[0] && ch[1]) cnlret("Impossible");
	if(ch[0]>1 || ch[1]>1) cnlret("Impossible");
	if(ch[0]) cnlret("Red wins");
	if(ch[1]) cnlret("Blue wins");
	cnl("Nobody wins");
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
    tc(tno);
    solve();
  }
}
