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
const int N = 600004;

const long long MAX_SIZE = 600005;

vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
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


map<int,int> fc;
int factorCount(int x)
{
  if(fc.find(x)==fc.end())
  {
    map<int,int> mp;
    while(x>1)
    {
      int y = SPF[x];
      mp[y]++;
      x/=y;
    }
    int tt=1;
    for(auto p: mp) tt*=(p.sn+1);
    fc[x]=tt;
  }
  return fc[x];
}
// (M = M mod b) mod a
// M mod a = r
// r = M mod b mod a
// M = abp + aq + r (r<a, aq+r<b, a<b)
// (M-M mod b) = a*t [t=b*p in the upper case]
// b*floor(M/b) = a*t (a<b)
intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  manipulated_seive(N);
  test(t)
  {
    int n,m; cin >> n >> m;
    set<int> s;
    int used[n]={}; b
    int ans = 0;
    for(int b= 2; b<=min(n,m); b++)
    {
      if(used[b]) continue;
      int c = m/b, d = b*c;
      used[b]=1;
      used[c]=1;
      int tt = factorCount(d);
      if(b==c) anas+= tt/2;
      else ans+=tt-1;
      csp(b); csp(c); csp(d); cnl(tt);
    }
    cnl(ans);
  }
}

// Find number of factors before x in M - f(x) (f(x)= 0...x-1)
// 1000 100001
