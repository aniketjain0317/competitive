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
typedef pair<int,int> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

void pairsort(ll a[], ll b[], int n)
{
    pair<ll, ll> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);
    // reverse(pairt,pairt+n);
    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        b[i] = pairt[i].second;
    }
    // reverse(b,b+n);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    ll n,m; cin >> n >> m;
    ll a[n]; cinp(n,a);
    ll b[n]; cinp(n,b);
    ll ind[n]={};
    fr(i,0,n) ind[i]=i;
    pairsort(a,ind,n);

    ll cap=-m;
    fr(i,0,n) cap+=a[i];
    if(cap<0) {cnl(-1); continue;}

    int vis[n]={};
    vpi diff[3];
    fr(i,0,n) diff[b[ind[i]]].pb({a[ind[i]],ind[i]});

    int i=0, j=0;

    ll cs = INF;
    ll sz1 = diff[1].size(), sz2 = diff[2].size();
    if(sz1>j+1) cs=diff[1][j].fs+diff[1][j+1].fs;

    int f=0;
    while(cap>0 && (i+j<k))
    {
      if(i==sz1) {f=1; break;}
      if(j==sz2) {f=2; break;}
      ll x = diff[2][i].fs;
      ll y = diff[1][j].fs

      if(x>cap) {f=1; break;}


      if(sz2>i && x<cs && x<=cap)
      {
        vis[diff[2][i].sn]=1;
        cap-=x;
        i++;
      }
      else
      {
        if(y>cap) break; // x>y, i.e.  all remaining elements are >cap
        vis[diff[1][j].sn]=1;
        cap-=y;
        cs-=y;
        if(sz1>++j) cs+=diff[1][j].fs;
        else cs=INF;
      }
      if(f) break;
    }
    if(cap>0 && diff[1][j].fs<=cap) vis[diff[1][j].sn]=1;
    ll ans=0;
    fr(i,0,n) if(!vis[i]) ans+=b[i];
    // csp("ANS");
    cnl(ans);
  }
}

// assume all removed;
// add some apps s.t.: atmost sum-m memory remains
// add apps with max val
// sum=15, m=6, cap=9, msum=7
// 1,2,3,4,6
// 2,1,1,1,2

// 1,6
// 2,3,4
// cs=y+y1;
// if(x<=cs) {push(i); i++;}
// else {push(y); cs-=y; j++; cs+=y2;}
