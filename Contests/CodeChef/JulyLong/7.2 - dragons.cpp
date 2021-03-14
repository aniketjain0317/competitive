// Problem
//

#include <bits/stdc++.h>
using namespace std;

// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
// #define M_E        2.71828182845904523536
// #define M_LOG2E    1.44269504088896340736
// #define M_LOG10E   0.434294481903251827651
// #define M_LN2      0.693147180559945309417
// #define M_LN10     2.30258509299404568402
// #define M_PI       3.14159265358979323846
// #define M_PI_2     1.57079632679489661923
// #define M_PI_4     0.785398163397448309616
// #define M_1_PI     0.318309886183790671538
// #define M_2_PI     0.636619772367581343076
// #define M_2_SQRTPI 1.12837916709551257390
// #define M_SQRT2    1.41421356237309504880
// #define M_SQRT1_2  0.707106781186547524401
// #endif
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
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;


// C++ program for range minimum
// query using segment tree
#include <bits/stdc++.h>
using namespace std;

// A utility function to get minimum of two numbers
ll minVal(ll x, ll y) { return (x < y)? x: y; }

// A utility function to get the
// middle index from corner indexes.
ll getMid(ll s, ll e) { return s + (e -s)/2; }

/* A recursive function to get the
minimum value in a given range
of array indexes. The following
are parameters for this function.

	st --> Pointer to segment tree
	index --> Index of current node in the
		segment tree. Initially 0 is
		passed as root is always at index 0
	ss & se --> Starting and ending indexes
				of the segment represented
				by current node, i.e., st[index]
	qs & qe --> Starting and ending indexes of query range */
ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
	// If segment of this node is a part
	// of given range, then return
	// the min of the segment
	if (qs <= ss && qe >= se)
		return st[index];

	// If segment of this node
	// is outside the given range
	if (se < qs || ss > qe)
		return INT_MAX;

	// If a part of this segment
	// overlaps with the given range
	ll mid = getMid(ss, se);
	return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
				RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range
// from index qs (query start) to
// qe (query end). It mainly uses RMQUtil()
ll RMQ(ll *st, ll n, ll qs, ll qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		cout<<"Invalid Input";
		return -1;
	}

	return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
ll constructSTUtil(ll arr[], ll ss, ll se,
								ll *st, ll si)
{
	// If there is one element in array,
	// store it in current node of
	// segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements,
	// then recur for left and right subtrees
	// and store the minimum of two values in this node
	ll mid = getMid(ss, se);
	st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
					constructSTUtil(arr, mid+1, se, st, si*2+2));
	return st[si];
}

/* Function to construct segment tree
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
ll *constructST(ll arr[], ll n)
{
	// Allocate memory for segment tree

	//Height of segment tree
	ll x = (ll)(ceil(log2(n)));

	// Maximum size of segment tree
	ll max_size = 2*(ll)pow(2, x) - 1;

	ll *st = new ll[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n-1, st, 0);

	// Return the constructed segment tree
	return st;
}

// Driver program to test above functions
// int main()
// {
// 	int arr[] = {1, 3, 2, 7, 9, 11};
// 	int n = sizeof(arr)/sizeof(arr[0]);
//
// 	// Build segment tree from given array
// 	int *st = constructST(arr, n);
//
// 	int qs = 1; // Starting index of query range
// 	int qe = 5; // Ending index of query range
//
// 	// Print minimum value in arr[qs..qe]
// 	cout<<"Minimum of values in range ["<<qs<<", "<<qe<<"] "<<
// 	"is = "<<RMQ(st, n, qs, qe)<<endl;
//
// 	return 0;
// }
//
// // This code is contributed by rathbhupendra


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int n,q; cin >> n >> q;
  ll height[n], neg[n];
  fr(i,0,n) {cin >> height[i]; neg[i]=-height[i];}
  ll taste[n];
  cinp(n,taste);
  ll *st = constructST(neg,n);
  ll dp[2][n];
  fr(k,0,2) fr(i,0,n) dp[k][i]=0;
  fr(i,0,n)
  {
    if(!dp[1][i]) dp[1][i]=taste[i];
    int min = -1;
    fr(j,i+1,n)
    {
      if(height[j]>=height[i]) break;
      if(height[j]<=min) continue;
      min=j;
      dp[1][j]=dp[1][i]+taste[j];
    }
  }

  for(int i=n-1;i>-1;i--)
  {
    if(!dp[0][i]) dp[0][i]=taste[i];
    int min = -1;
    for(int j = i-1;j>-1;j--)
    {
      if(height[j]>=height[i]) break;
      if(height[j]<=min) continue;
      min=j;
      dp[0][j]=dp[0][i]+taste[j];
    }
  }

  fr(i,0,q)
  {
    int a,b,c; cin >> a >> b >> c;
    if(a==1)
    {
      b--;
      taste[b]=c;
      fr(k,0,2) fr(i,0,n) dp[k][i]=0;
      fr(i,0,n)
      {
        if(!dp[1][i]) dp[1][i]=taste[i];
        int min = -1;
        fr(j,i+1,n)
        {
          if(height[j]>=height[i]) break;
          if(height[j]<=min) continue;
          min=j;
          dp[1][j]=dp[1][i]+taste[j];
        }
      }

      for(int i=n-1;i>-1;i--)
      {
        if(!dp[0][i]) dp[0][i]=taste[i];
        int min = -1;
        for(int j = i-1;j>-1;j--)
        {
          if(height[j]>=height[i]) break;
          if(height[j]<=min) continue;
          min=j;
          dp[0][j]=dp[0][i]+taste[j];
        }
      }
    }
    if(a==2)
    {
      b--; c--;
      int ss,se,id=-1;
      if(b>c) {ss=c;se=b;id=0;}
      else if(c>b) {ss=b;se=c;id=1;}
      else {cnl(taste[b]);}
      ll x = RMQ(st,n,ss,se);
      // cnl(ss<<" "<<se<<" "<<x);
      if(-x!=height[b]) {cnl(-1); continue;}
      ll ans = dp[id][c] - dp[id][b]+taste[b];
      cnl(ans);
    }
  }
}
