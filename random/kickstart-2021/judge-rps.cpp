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
typedef vector<char> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  double w = 1;
  double e = 0;
  int n = 60; int kt = 3;
  double ans[kt] = {};
  vvi s(kt, vi(n));

  // 20,20,20
  fr(i,0,n)
  {
    if(i<20) s[0][i]='r';
    else if(i<40) s[0][i]='s';
    else s[0][i]='p';
  }

  // 10,20,30
  fr(i,0,n)
  {
    if(i<10) s[1][i]='r';
    else if(i<30) s[1][i]='s';
    else s[1][i]='p';
  }

  // rsp
  fr(i,0,n)
  {
    if(i%3==0) s[2][i]='r';
    if(i%3==1) s[2][i]='s';
    if(i%3==2) s[2][i]='p';
  }

  map<char,char> ctr; // ctr[x] = y: x wins against y.
  ctr['r']='s'; ctr['s']='p'; ctr['p']='r';

  map<char,char> loss; // loss[x] = y: x loses against y.
  loss['r']='p'; loss['s']='r'; loss['p']='s';
  fr(k,0,kt)
  {
    map<char,int> mp;
    mp['r']=0;
    mp['s']=0;
    mp['p']=0;
    fr(i,0,n)
    {
      char x = s[k][i];
      if(!i) ans[k] += w/3 + e/3;
      else
      {
        double curr = mp[ctr[x]]*w + mp[x]*e;
        ans[k] += curr/i;
      }
      mp[loss[x]]++;
      // csp(i); csp(mp['r']); csp(mp['s']); cnl(mp['p']);
    }
    cnl(ans[k]);
  }
}
// rsprsprsprsprsp : 8.6243672993672984
// rrrrrsssssppppp : 8.8255217005216995

// rsprsp: 38.159847192969174
// 20, 20, 20: 37.357384883838861
// 10,20,30: 34.308812256518351
