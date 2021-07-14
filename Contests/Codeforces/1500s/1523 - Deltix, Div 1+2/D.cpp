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
const int N = 200005;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m,p; cin >> n >> m >> p;
  int THRESHOLD = ceil(n/2.0);
  char inp[n][m]={};
  fr(i,0,n) fr(j,0,m) cin >> inp[i][j];
  vi curr[m];
  fr(i,0,n) fr(j,0,m) if(inp[i][j]=='1') curr[j].pb(i);
  int dp[m+1][m+1]={};
  string ans[m+1][m+1]={};
  ans[0][0]="";
  frr(i,1,m) ans[i][0]=ans[i-1][0]+'0';
  // fr(i,0,m) showVI(curr[i]);
  // i: 1 indexed; 1 to m
  // j: 1 indexed;
  // dp[i][j] = max val after selecting i currs out of the first j currs
  frr(i,1,m)
  {
    frr(j,1,i)
    {
      int score = 0;
      for(auto &p: curr[i-1])
      {
        int f = 1;
        fr(c,0,i-1) if(ans[i-1][j-1][c]=='1' && inp[p][c]=='0')
        {f=0; break;}
        score+=f;
      }
      if(score>=dp[i-1][j])
      {
        dp[i][j]=score;
        ans[i][j]=ans[i-1][j-1]+'1';
      }
      else
      {
        dp[i][j] = dp[i-1][j];
        ans[i][j] = ans[i-1][j]+'0';
      }
    }
    // show2d(m+1, m+1,ans);
    // show2d(m+1, m+1,dp);
  }
  // cnl(THRESHOLD);
  // show2d(m+1, m+1, dp);
  int mx = 0;
  frr(j,0,m) if(dp[m][j]>=THRESHOLD) mx = j;
  cnl(ans[m][mx]);
}
