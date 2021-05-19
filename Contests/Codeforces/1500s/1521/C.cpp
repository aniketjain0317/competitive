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
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
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
const int N = 100005;

int n;
int p[N]={};
int qmax(int i, int j)
{
  int a;
  cout << "? 1 "; csp(i+1); csp(j+1); cnl(n-1);
  cin >> a;
  if(a==n-1)
  {
    int a2;
    cout << "? 1 "; csp(j+1); csp(i+1); cnl(n-1);
    cin >> a2;
    a = max(a,a2);
  }
  return a;
}

int qmin(int i, int j)
{
  int b;
  cout << "? 2 "; csp(i+1); csp(j+1); cnl(1);
  cin >> b;
  if(b==2)
  {
    int b2;
    cout << "? 2 "; csp(j+1); csp(i+1); cnl(1);
    cin >> b2;
    b = min(b,b2);
  }
  return b;
}

void query(int i, int j, int k)
{
  int a,b,c,d;
  a = qmax(i,j);
  b = qmin(i,j);
  c = qmax(i,k);
  d = qmin(i,k);

  // csp(a); csp(b); csp(c); cnl(d);

  if(a==c) {p[i]=a; p[j]=b; p[k]=d;}
  else if(a==d) {p[i]=a; p[j]=b; p[k]=c;}
  else if(b==c) {p[i]=b; p[j]=a; p[k]=d;}
  else if(b==d) {p[i]=b; p[j]=a; p[k]=c;}
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
    cin >> n;
    for(int i =0; i+2<n; i+=3)
    {
      query(i,i+1,i+2);
    }

    if(n%3==1) query(0,1,n-1);
    else if(n%3==2) query(0,n-2,n-1);

    csp("!");
    show1d(n,p);
  }
}
