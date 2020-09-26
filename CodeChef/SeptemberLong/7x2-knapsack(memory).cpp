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
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1e5
#define INF 1e9+5

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int n=0;
unordered_map<ll,int> dp[60];
// Returns the value of maximum profit
void display(vi p)
{
  int ans[n]={};
  for(auto x: p) ans[x-1]=1;
  for(auto x: ans) cout << x;
  cout << endl;
}
ll knapSackRec(ll W, ll wt[], ll val[],
				int i)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i].count(W))
		return dp[i][W];

	if (wt[i] > W) {

		// Store the value of function call
		// stack in table before return
		dp[i][W] = knapSackRec(
W, wt, val, i - 1);
		return dp[i][W];
	}
	else {

		// Store value in a table before return
		dp[i][W] = max(
			val[i] + knapSackRec(
						W - wt[i], wt, val, i - 1),
			knapSackRec(W, wt, val, i - 1));

		// Return value of table after storing
		return dp[i][W];
	}
}

int knaparr(ll wt[], int n, ll w, vi p)
{
  // vshow1d(p);
  if(n==0)
  {
    // for(int i=0;i<p.size();i++) cout << p[i] << endl;
    display(p);
    return 1;
  }
  // else if(!K[n][w]) return 0;
  int next=0;
  for(int i =n;i>=0;i--)
  {
    if(knapSackRec(w, wt, wt, n-1)==knapSackRec(w,wt,wt,i)) continue;
    p.push_back(i+1);
    next=i;
    break;
  }
  knaparr(wt,next,w-wt[next],p);
  return 1;
}

int main()
{
  n=45;
  int k=4;
  ll wt[n]={};
  ll sumtt=0;
  frr(i,1,n)
  {
    int j = 1;
    fr(aarwd,0,k) j*=i;
    wt[i-1]=j;
    sumtt+=j;
  }
  ll sum=sumtt/2;
	ll sf = knapSackRec(sum, wt, wt, n-1);
  vi p;
  knaparr(wt,n,sum,p);
  cnl(sumtt-2*sf);
  return 0;
}
