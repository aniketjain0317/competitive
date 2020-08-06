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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

ll a[3],p[3];
int check2(int i,int op)
{
  int s1 = (i+1)%3, s2 = (i+2)%3;
  if(p[s1]-a[s1]==p[s2]-a[s2]) return op;
  if(a[s1] && a[s2] && p[s1]%a[s1]==0 && p[s2]%a[s2]==0) if(p[s1]/a[s1]==p[s2]/a[s2]) return op;
  return op+1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  test(t)
  {
    int flag=0;
    cin >> a[0] >> a[1] >> a[2] >> p[0] >> p[1] >> p[2];
    int same = 0;
    int sn = -1;
    if(p[0]==a[0]) {same++; sn=0;}
    if(p[1]==a[1]) {same++; sn=1;}
    if(p[2]==a[2]) {same++; sn=2;}

    if(same==3) {cnl(0); continue;}
    if(same==2) {cnl(1); continue;}
    // 2
    if(same==1)
    {
      int ans = check2(sn,1);
      cnl(ans); continue;
    }
    // 3
    if(p[0]-a[0]==p[1]-a[1] && p[0]-a[0]==p[2]-a[2]) {cnl(1); continue;}
    if(a[1] && a[2] && a[0] && p[1]%a[1]==0 && p[2]%a[2]==0 && p[0]%a[0]==0) if(p[1]/a[1]==p[2]/a[2] &&p[1]/a[1]==p[0]/a[0]) {cnl(1); continue;}
    // 2,1
    fr(i,0,3)
    {
      int ans = check2(i,2);
      if(ans==2) {cnl(ans); flag=1; break;}
    }
    if(flag) continue;

    // 3,3 && 2,3
    fr(i,0,3)
    {
      int s1 = (i+1)%3, s2 = (i+2)%3;
      if(a[s1]-a[s2]==0) continue;
      if((p[s2]-p[s1])%(a[s2]-a[s1])==0)
      {
        ll m = (p[s2]-p[s1])/(a[s2]-a[s1]);
        ll c = p[s1] - a[s1]*m;
        if(m*a[i]+c==p[i]) {cnl(2); flag=1; break;}
        if(a[i]+c==p[i]) {cnl(2); flag=1; break;}
        if(m*a[i]==p[i]) {cnl(2); flag=1; break;}
      }
    }
    if(flag) continue;

    // 2,2
    fr(i,0,3)
    {
      int s1 = (i+1)%3, s2 = (i+2)%3;
      // ++
      if(p[s1]-a[s1]+p[s2]-a[s2]==p[i]-a[i]) {cnl(2); flag=1; break;}
      // +x
      if((a[i]+p[s1]-a[s1]) && a[s2] && p[i]%(a[i]+p[s1]-a[s1])==0 && p[s2]%a[s2]==0) if(p[i]/(a[i]+p[s1]-a[s1])==p[s2]/a[s2]) {cnl(2); flag=1; break;}
      if((a[i]+p[s2]-a[s2]) && a[s1] && p[i]%(a[i]+p[s2]-a[s2])==0 && p[s1]%a[s1]==0) if(p[i]/(a[i]+p[s2]-a[s2])==p[s1]/a[s1]) {cnl(2); flag=1; break;}
      // X+
      if(a[s1] && p[s1]%a[s1]==0) if(((a[i]*p[s1]/a[s1]) + p[s2]-a[s2]) == p[i]) {cnl(2); flag=1; break;}
      if(a[s2] && p[s2]%a[s2]==0) if(((a[i]*p[s2]/a[s2]) + p[s1]-a[s1]) == p[i]) {cnl(2); flag=1; break;}
      // xx
      if(a[0] && a[1] && a[2] && p[1]%a[1]==0 && p[2]%a[2]==0 && p[0]%a[0]==0) if(a[i] * p[s1] * p[s2] / (a[s1] * a[s2]) == p[i]) {cnl(2); flag=1; break;}
    }
    if(flag) continue;


    // 3,2
    fr(i,0,3)
    {
      int s1 = (i+1)%3, s2 = (i+2)%3;
      // +x
      ll plus = p[i] - a[i];
      ll an[3] = {0,a[s1]+plus,a[s2]+plus};
      if(an[1] && an[2]) if(p[s2]%an[2]==0 && p[s1]%an[1]==0) if(p[s2]/an[2]==p[s1]/an[1]) {cnl(2); flag=1; break;}
    }
    if(flag) continue;
    cnl(3);
  }
}
