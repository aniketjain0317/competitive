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
const int N = 300;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n; cin >> n;
  double m = n;
  vi init(4,0);
  fr(i,0,n)
  {
    int x; cin >> x;
    init[x-1]++;
  }
  map<vi, double> dp;
  frr(l,0,n)
  {
    frr(k,0,n-l)
    {
      frr(j,0,n-k-l)
      {
        int i = n-k-l-j;
        vi v({j,k,l});
        if(i==n) continue;
        dp[{j,k,l}] += i;
        if(j) dp[v] += j*(1+dp[{j-1,k,l}]);
        if(k) dp[v] += k*(1+dp[{j+1,k-1,l}]);
        if(l) dp[v] += l*(1+dp[{j,k+1,l-1}]);
        dp[v]/=m-i;
        if(init==v) goto print;
      }
    }
  }
  print:
    cnl(dp[init]);
}
//
// dp[n][n][n][n]={};
// dp[i][j][k][l] //i+j+k+l==n => dp gives expected number of tries to get to 0
// (299,1,0,0) = 1 *(1+ dp[300][0][0][0]) + 299 * (1+ 299,1,0,0)
// (n/j) * dp[i+1][j-1][k][l]
// dp[i][j][k][l] = (i + (j)*(1+dp[i+1][j-1][k][l]) + (k)*dp[i][j+1][k-1][l] + (l)*dp[i][j][k+1][l-1])/(n-i);
