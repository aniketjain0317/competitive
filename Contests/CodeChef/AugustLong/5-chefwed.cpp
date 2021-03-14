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
#define INF 100000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

vi ans;
int n,k;
int fn(int s, int fam[], int cumfam[][1001]);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    cin >> n >> k;
    int fam[n]={};
    int cumfam[101][1001]={};
    cinp(n,fam);
    cumfam[fam[0]][0]++;
    fr(i,1,n)
    {
      int x = fam[i];
      frr(j,1,100)
      {
        cumfam[j][i]=cumfam[j][i-1]+(j==x);
      }
    }
    int icost=k;
    frr(i,1,100)
    {
      if(cumfam[i][n-1]>1) icost+=cumfam[i][n-1];
    }
    int fcost= fn(0,fam,cumfam);
    cnl(min(icost,fcost));
    ans.clear();
  }
}

int fn(int s, int fam[], int cumfam[][1001])
{
  // cnl("A"<<s);
  int mx=-INF,mxi=-1;
  int prof=0;
  int vis[100]={};
  fr(i,s,n)
  {
    int x = fam[i];
    if(!vis[x])
    {
      prof+=1;
      vis[x]=1;
    }
    else
    {
      prof-=1;
    }
    if(cumfam[x][n-1]-cumfam[x][i]==1) prof+=1;
    if(prof>mx) {mx=prof;mxi=i;}
    // cnl("B"<<prof<<" "<<i);
  }
  if(mxi==n-1)
  {
    int cost = (ans.size()+1)*k;
    int xi=0;
    vi fvis;
    fvis.resize(101,0);
    fr(i,0,n)
    {
      int x = fam[i];
      if(!fvis[x]) fvis[x]=1;
      else if(fvis[x]==1) {cost+=2; fvis[x]=2;}
      else cost+=1;

      if(ans.size()>xi && ans[xi]==i) {xi++;fvis.clear(); fvis.resize(101,0);}
    }
    return cost;
  }
  else
  {
    ans.pb(mxi);
    return fn(mxi+1,fam,cumfam);
  }
}
/*
Hello there, folks.
The competetive department of Coding Club is bringing to you a series of sessions designed to further your capabilites of solving competetive programming questions!
We'll be covering how to approach general questions regarding arrays, as well as some concepts like binary search and sorting.
Join us tommorrow (14 Aug, Friday) at 3:30 pm for our first session this semester!
P.S. People who are interested in attending these sessions, we ask you to join our competetive coding group so we can tackle doubts together.

Timings: 14 Aug, Friday, 3:30 pm
Prerequisites: Basic knowledge of C++
Whatsapp Group Link: https://chat.whatsapp.com/HgC5vqEYs1L8NplFJB8AAy
*/
