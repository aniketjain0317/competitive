// Problem
// AC

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
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("myans.txt","w",stdout);
  freopen("input.txt","r",stdin);

  int n,m; cin >> n >> m;
  // N , E , S , W
  int xdir[4]={0,1,0,-1};
  int ydir[4]={1,0,-1,0};
  char itodir[4]={'N','E','S','W'};
  map<char,int> dirtoi;
  dirtoi['N']=0;
  dirtoi['E']=1;
  dirtoi['S']=2;
  dirtoi['W']=3;
  int ind=0;
  bool lost[n+1][m+1]={};
  while(true)
  {
    ind++;
    int flag=0;
    int x,y; char c;
    cin >> x>>y >> c;
    string s; cin >> s;
    int xn=x,yn=y;
    int q=dirtoi[c];
    if(s.size()) flag=2;
    for(auto ch: s)
    {
      if(ch=='R') {q++; if(q==4) q=0;}
      if(ch=='L') {q--; if(q==-1) q=3;}
      if(ch=='F')
      {
        xn=x+xdir[q];yn=y+ydir[q];
        if(xn<0||xn>n||yn<0||yn>m)
        {
          if(lost[x][y]) {
            // cnl("Aaaaaaaaaaaaaaaaa "<<ind);
            continue;}
          lost[x][y]=1;
          // cnl("Bbbbbbbbbbbbbbbb"<<ind);
          // show2d(n+1,m+1,lost);
          csp(x); csp(y); csp(itodir[q]); cnl("LOST");
          flag=1;break;
        }
        else
        {
          x=xn;y=yn;
        }
      }
      // if(ind==58) {csp(ch<<":"<<q); csp(x); csp(y); cnl(itodir[q]);}
    }
    if(flag==2) {csp(x); csp(y); cnl(itodir[q]);}
  }
}
