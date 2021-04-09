// Problem
//

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


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
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}

typedef long long ll;
typedef pair<ll,int> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

class DisjSet {
	int *rank, *parent, n;

public:
	// Constructor to create and
	// initialize sets of n items
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	// Creates n single item sets
	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

  void make_set(int v)
  {
    parent[v] = v;
  }

	// Finds set of given item x
	int find(int x)
	{
		// Finds the representative of the set
		// that x is an element of
		if (parent[x] != x) {

			// if x is not the parent of itself
			// Then x is not the representative of
			// his set,
			parent[x] = find(parent[x]);

			// so we recursively call Find on its parent
			// and move i's node directly under the
			// representative of this set
		}

		return parent[x];
	}

	// Do union of two sets represented
	// by x and y.
	void Union(int x, int y)
	{
		// Find current sets of x and y
		int xset = find(x);
		int yset = find(y);

		// If they are already in same set
		if (xset == yset)
			return;

		// Put smaller ranked item under
		// bigger ranked item if ranks are
		// different
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}

		// If ranks are same, then increment
		// rank.
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n; cin >> n;
  ll xa[n], ya[n];
  fr(i,0,n) cin >> xa[i] >> ya[i];
  ll cost=0;
  vpi xs,ys;
  fr(i,0,n) xs.pb({xa[i],i});
  fr(i,0,n) ys.pb({ya[i],i});
  sort(all(xs));
  sort(all(ys));
  priority_queue<vi, vvi, greater<vi>> pq;
  fr(i,1,n-1)
  {
    vi vx,vy, vy2, vx2;
    {
      vx.pb(xs[i].fs-xs[i-1].fs);
      vx.pb(xs[i].sn);
      vx.pb(xs[i-1].sn);
      pq.push(vx);
    }
    {
      vx2.pb(xs[i+1].fs-xs[i].fs);
      vx2.pb(xs[i+1].sn);
      vx2.pb(xs[i].sn);
      pq.push(vx2);
    }

    {
      vy.pb(ys[i].fs-ys[i-1].fs);
      vy.pb(ys[i].sn);
      vy.pb(ys[i-1].sn);
      pq.push(vy);
    }
    {
      vy2.pb(ys[i+1].fs-ys[i].fs);
      vy2.pb(ys[i+1].sn);
      vy2.pb(ys[i].sn);
      pq.push(vy2);
    }
  }
  DisjSet dsu(n);
  while(!pq.empty())
  {
    vi v = pq.top();
    // show1d(3,v);
    pq.pop();
    if(dsu.find(v[1])!=dsu.find(v[2]))
    {
      cost+=v[0];
      dsu.Union(v[1],v[2]);
    }
  }
  cnl(cost);
}
