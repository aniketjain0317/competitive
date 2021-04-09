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
#define N 100000
#define INF 1e9+5

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef priority_queue<int> pq;

int dp[100][100]={};
// dp[n+1][w+1]={};


void knapsack(int n, int w, int wt[], int val[], vi p, int k)
{
  frr(i,0,n) frr(j,0,w) dp[i][j]=0;
  frr(i,1,n)
  {
    int wi = wt[i-1];
    int vali = val[i-1];
    frr(j,1,w)
    {
      // a : object i is not selected
      // b : object i is selected, and added to the max val of j-wt[i]
      int a=0,b=0;
      a=dp[i-1][j];
      if(j>=wt[i]) b = dp[i-1][j-wi]+vali;
      dp[i][j]=max(a,b);
      p[a%k]=max(p[a%k],a);
      p[b%k]=max(p[b%k],b);
    }
  }
  show1d(k,p);
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m,k; cin >> n >> m >> k;
  int arr[n][m]={};
  fr(i,0,n) fr(j,0,m) cin >> arr[i][j];

  int totalmod[n+1][k]={};
  fr(i,0,n)
  {
    vi rowmod(k,0);
    int wt[m]={}; fr(j,0,m) wt[j]=1;
    fr(j,0,m)
    {
      
    }

    fr(x,0,k)
    {
      int mx=0;
      fr(y,0,k)
      {
        int z = x - y;
        if(z<0) z+=k;
        mx = max(mx, totalmod[i][y]+rowmod[z]);
        // cnl(mx);
      }
      totalmod[i+1][x]=mx;
    }
  }
  cnl(totalmod[n][0]);

}
