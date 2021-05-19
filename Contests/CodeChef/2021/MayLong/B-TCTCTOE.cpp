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

int solve(vvi mat, int fs = 0)
{
  int xno = 0, yno = 0;
  fr(i,0,3) fr(j,0,3) xno+=(mat[i][j]=='X');
  fr(i,0,3) fr(j,0,3) yno+=(mat[i][j]=='O');

  if((xno-yno)>1 || (xno-yno)<0) return 3;

  int so = 0, sx = 0;
  fr(i,0,3)
  {
    int fo = 0, fx=0;
    fr(j,0,3) if(mat[i][j]!='O') fo=1;
    fr(j,0,3) if(mat[i][j]!='X') fx=1;

    if(!fo) so++;
    if(!fx) sx++;
  }
  fr(j,0,3)
  {
    int fo = 0, fx=0;
    fr(i,0,3) if(mat[i][j]!='O') fo=1;
    fr(i,0,3) if(mat[i][j]!='X') fx=1;

    if(!fo) so++;
    if(!fx) sx++;
  }

  {
    int fo = 0, fx=0;
    fr(i,0,3) if(mat[i][i]!='O') fo=1;
    fr(i,0,3) if(mat[i][i]!='X') fx=1;

    if(!fo) so++;
    if(!fx) sx++;
  }

  {
    int fo = 0, fx=0;
    fr(i,0,3) if(mat[i][2-i]!='O') fo=1;
    fr(i,0,3) if(mat[i][2-i]!='X') fx=1;

    if(!fo) so++;
    if(!fx) sx++;
  }
  if(!so && !sx)
  {
    if((xno+yno)==9) return 1;
    else return 2;
  }
  if(so && sx) return 3;
  return 4;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    vvi mat(3,vi(3));
    fr(i,0,3) fr(j,0,3) cin >> mat[i][j];

    int x = solve(mat);

    if(x!=4) {cnl(x); continue;}

    int f = 3;
    fr(i,0,3) fr(j,0,3)
    {
      if(mat[i][j]=='_') continue;
      vvi mat2(mat);
      mat2[i][j]='_';
      int x = solve(mat2);
      if(x==2) {f=1; goto final;}
    }
    final:
      cnl(f);
  }
}
