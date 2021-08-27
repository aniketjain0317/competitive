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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
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
const ll INF = 1LL<<60;
const int N = 1000005;

class DisjSet
{
	int *size, *parent, n;

public:
	DisjSet(int n)
	{
		size = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	void makeSet()
	{
		for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      size[i]=1;
    }
	}

	int find(int x)
	{
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}

	int merge(int x, int y)
	{
		int xset = find(x);
		int yset = find(y);

		if (xset == yset)
			return 0;
		if (size[xset] < size[yset]) swap(xset,yset);
		parent[yset] = xset;
		size[xset] += size[yset];
		return 1;
	}

  int getSize(int x)
  {
    int xset = find(x);
    return size[xset];
  }
};

const long long MAX_SIZE = 1000005;

vector<bool>      isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
    SPF[1]=1;
    for (ll i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (ll j=0;
             j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  manipulated_seive(MAX_SIZE);
  test(t)
  {
    int n; cin >> n;
    vi r(n); cin >> r;
    map<int,int> adj;
    DisjSet dsu(n);
    fr(i,0,n)
    {
      int ch = r[i];
      int x = SPF[ch];
      r[i] = x;
      while(ch>1)
      {
        if(!adj.count(x)) adj[x]=i;
        else dsu.merge(adj[x],i);
        while(ch%x==0) ch/=x;
        x=SPF[ch];
      }
    }

    int cnt = 0, ans = 0;
    bool visited[n]={};
    for(int i = 0; i<n; i++)
    {
      int ch = dsu.find(i);
      if(!visited[ch]) cnt++;
      visited[ch]=1;
    }
    if(cnt==1) ans = 0;
    else if(adj.count(2)) ans = (cnt-1)*2;
    else
    {
      if(cnt==2 && adj.count(3)) ans = 3;
      else ans = cnt*2;
    }
    cnl(ans);
  }
}
