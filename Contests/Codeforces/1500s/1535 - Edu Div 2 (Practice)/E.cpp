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

const ll MOD = 1000000007;
const int N = 300005;
const int K = 19;


intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int gold[N]={};
  int cost[N]={};
  int up[N][K+1]={};
  int q, a0, c0; cin >> q >> a0 >> c0;
  gold[1] = a0;
  cost[1] = c0;
  frr(i,2,q+1)
  {
    int ch; cin >> ch;
    if(ch==1)
    {
      int p,a,c; cin >> p >> a >> c; p++;
      gold[i] = a;
      cost[i] = c;
      up[i][0] = p;
      frr(x,1,K) up[i][x] = up[up[i][x-1]][x-1];
    }
    else
    {
      int v, w; cin >> v >> w; v++;
      int l = 0;
      int n = v; 
      frrb(x,K,0) if(gold[up[n][x]]) l+=(1ll<<x), n = up[n][x];
      int fw = w, fc = 0;
      while(fw)
      {
        int wn = min(fw, gold[n]);
        fw-=wn;
        fc += wn*cost[n];
        gold[n] -= wn;
        if(n==v) break;
        l--; n=v;
        frr(i,0,K) if(l & 1ll<<i) n = up[n][i];
      }
      csp(w-fw); cnl(fc);
    }
  }
}
