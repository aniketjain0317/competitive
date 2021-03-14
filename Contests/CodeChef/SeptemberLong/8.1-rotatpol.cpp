// Problem
//ACCCCCCCCCCCCCC

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
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1e5
#define INF 1e9+5

typedef long long ll;
// struct Point {
//     double x, y;
//     bool operator==(const Point& p) const {
//         return p.fs == x && p.sn == y;
//     }
//     bool operator!=(const Point& p) const {
//         return !(p == *this);
//     }
//     Point operator+(const Point& rhs) const {
//         return {x + rhs.fs, y + rhs.sn};
//     }
//     Point operator-(const Point& rhs) const {
//         return {x - rhs.fs, y - rhs.sn};
//     }
//     void operator+=(const Point& rhs) {
//         x += rhs.fs;
//         y += rhs.sn;
//     }
//     friend ostream& operator<<(ostream& os, const Point& p) {
//         os << "x = " << p.fs << ", y = " << p.sn;
//         return os;
//     }
// };



typedef pair<double,double> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef set<pi> spi;

double constrainAngle(double x){
    x = fmod(x + 180,360);
    if (x < 0)
        x += 360;
    return x - 180;
}

// void display(spi ls[])
// {
//   for(auto s: ls)
//   {
//     for(auto p: s)
//     {
//         double x = p.fs;
//         double y = p.sn;
//         csp("("<<x<<", "<<y<<")");
//     }
//     cout << endl;
//   }
// }

spi rng(ll x1, ll y1, ll x2, ll y2)
{
  ll vecx = x2-x1;
  ll vecy = y2-y1;
  double ang=atan2(vecy,vecx) * 180 / M_PI;
  pi ans1,ans2;
  spi s1;
  ans1.fs=(constrainAngle(ang-90));
  ans1.sn=(constrainAngle(ang+90));
  if(ans1.fs>ans1.sn)
  {
    ans2.fs=-180;
    ans2.sn=ans1.sn;
    ans1.sn=180;
    s1.insert(ans2);
  }
  s1.insert(ans1);
  return s1;
}

spi unn(spi r1, spi r2)
{
  spi ans;
  if(r1.empty()) return r2;
  if(r2.empty()) return r1;
  spi all = r1;
  for(auto p: r2) all.insert(p);
  auto it = all.begin();
  ans.insert(*it);
  it++;
  while(it!=all.end())
  {
    auto ch = prev(ans.end());
    if(ch->sn > it->fs)
    {
      double a1 = (*ch).fs;
      double a2 = (*ch).sn;
      a2 = max(a2,(*it).sn);
      ans.erase(ch);
      pi p1(a1,a2);
      if(a1!=a2) ans.insert(p1);
    }
    else ans.insert(*it);
    it++;
  }
  return ans;
}

spi ints(spi r1, spi r2)
{
  spi ans;
  if(r1.empty()) return ans;
  if(r2.empty()) return ans;

  for(auto p: r2)
  {
    pi p1(p.fs,p.fs);
    pi p2(p.sn,p.sn);
    auto it1 = r1.lb(p1);
    auto it2 = r1.lb(p2);



    if(it1!=r1.begin()) it1--;
    for(auto it=it1;it!=it2;it++)
    {
      pi pp = *it;
      if(p.fs>pp.sn) continue;
      if(p.sn<pp.fs)break;
      double a,b;
      a = max(p.fs,pp.fs);
      b = min(p.sn,pp.sn);
      pi inse(a,b);
      if(a!=b) ans.insert(inse);
    }
  }
  return ans;
}

pi angtov(double ang)
{
  double ang2 = ang * M_PI / 180;
  int k = 1e9;
  int a = k*cos(ang2);
  int b = k*sin(ang2);
  pi p(a,b);
  return p;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  // cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","a",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n; cin >> n;
    ll arrx[n]={};
    ll arry[n]={};
    fr(i,0,n) cin >> arrx[i] >> arry[i];

    spi ls[n], ls2[n];
    fr(i,0,n-1)
    {
      ls[i]=(rng(arrx[i],arry[i],arrx[i+1],arry[i+1]));
      ls2[i]=(rng(arrx[i+1],arry[i+1],arrx[i],arry[i]));
    }
    ls[n-1]=rng(arrx[n-1],arry[n-1],arrx[0],arry[0]);
    ls2[n-1]=rng(arrx[0],arry[0],arrx[n-1],arry[n-1]);

      // for(auto s: ls)
      // {
      //   for(auto p: s)
      //   {
      //       double x = p.fs;
      //       double y = p.sn;
      //       csp("("<<x<<", "<<y<<")");
      //   }
      //   cout << endl;
      // }

    spi dp[3][n]={};
    dp[0][0]=ls[0];
    fr(i,1,n)
    {
      dp[0][i]=ints(dp[0][i-1],ls[i]);
      spi k1 = unn(dp[0][i-1],dp[1][i-1]);
      dp[1][i]=ints(k1,ls2[i]);
      spi k2 = unn(dp[1][i-1],dp[2][i-1]);
      dp[2][i]=ints(k2,ls[i]);
    }
    int flag=0;
    fr(k,0,3) if(!dp[k][n-1].empty())
    {
      for(auto p: dp[k][n-1])
      {
        if(p.fs==p.sn) continue;
        double ang = (p.fs + p.sn)/2;
        pi ans=angtov(ang);
        double ang2 = atan2(ans.sn,ans.fs) * 180 / M_PI;
        // if(!(ans.fs<ang2 && ang2<ans.sn)) continue;
        cnl((int)ans.fs << " " << (int)ans.sn);
        flag=1;break;
      }
      if(flag) break;
    }
    if(!flag) cnl("0 0");
  }
}
