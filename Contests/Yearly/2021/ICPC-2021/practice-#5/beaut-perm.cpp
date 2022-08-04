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
#define M_PI_2     1.57079632679489661923a
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
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
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

	void merge(int x, int y)
	{
		int xset = find(x);
		int yset = find(y);

		if (xset == yset)
			return;
		if (size[xset] < size[yset]) swap(xset,yset);
		parent[yset] = xset;
		size[xset] += size[yset];
	}

  int getSize(int x)
  {
    int xset = find(x);
    return size[xset];
  }
};


intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    ainp(n,arr);
    vpi cost(n);
    fr(i,0,n)
    {
      cin >> cost[i].fs;
      cost[i].sn=i;
    }
    sort(all(cost));

    DisjSet dsu(n);
    fr(i,0,n) dsu.merge(i,arr[i]-1);

    vvi cnew;
    int ans=0;
    fr(i,0,n-1)
    {
      vi v(3);
      v[0] = abs(cost[i+1].fs-cost[i].fs);
      v[1] = cost[i].sn;
      v[2] = cost[i+1].sn;
      cnew.pb(v);
    }
    sort(all(cnew));
    for(auto v: cnew)
    {
      int x = dsu.find(v[1]);
      int y = dsu.find(v[2]);
      if(x!=y)
      {
        dsu.merge(x,y);
        ans+=v[0];
      }
    }
    cnl(ans);
  }
}
