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

struct Point {
    ll x, y;
    bool operator==(const Point& p) const {
        return p.x == x && p.y == y;
    }
    bool operator!=(const Point& p) const {
        return !(p == *this);
    }
    Point operator+(const Point& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
    void operator+=(const Point& rhs) {
        x += rhs.x;
        y += rhs.y;
    }
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "x = " << p.x << ", y = " << p.y;
        return os;
    }
};

typedef Point pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

double constrainAngle(double x){
    x = fmod(x + 180,360);
    if (x < 0)
        x += 360;
    return x - 180;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  test(t)
  {
    int n; cin >> n;
    pi arr[n]={};
    fr(i,0,n) cin >> arr[i].x >> arr[i].y;
    pi vecs[n]={};
    double ang[n]={};
    fr(i,1,n)
    {
      vecs[i-1]=arr[i]-arr[i-1];
      ang[i-1]=atan2(vecs[i-1].y,vecs[i-1].x) * 180 / M_PI;
    }
    vecs[n-1]=arr[0]-arr[n-1];
    ang[n-1]=atan2(vecs[n-1].y,vecs[n-1].x) * 180 / M_PI;

    vector<double> angs(ang,ang+n);
    int flag=0;
    double ans = 0;
    fr(i,0,n)
    {
      int tx=4;
      double x[tx] = {constrainAngle(ang[i] + 89.99),constrainAngle(ang[i]+90.01),constrainAngle(ang[i] - 89.99),constrainAngle(ang[i]-90.01)};
      int ch[tx] = {};
      int ps[tx] = {};
      fr(k,0,tx)
      {
        fr(j,0,n)
        {
          if(abs(constrainAngle(x[k]-ang[j]))>90)
          {
            if(ps[k]==0) ps[k]=-1;
            if(ps[k]==1) {ps[k]=-1;ch[k]++;}
          }
          else if(abs(x[k]-ang[j])<90)
          {
            if(ps[k]==0) ps[k]=1;
            if(ps[k]==-1) {ps[k]=1;ch[k]++;}
          }
          // if(j==4) cnl("BRUH "<<x[k]<<" "<<ang[j]<<" "<<abs(constrainAngle(x[k]-ang[j])));
        }
        if(ch[k]<=2)
        {
          flag=1; ans = x[k];
          break;
        }
      }
      if(flag) break;
    }
    if(!flag) {cnl("0 0"); continue;}
    double ans2 = ans *  M_PI /180;
    long double ax = 1e5 * cos(ans2), ay = 1e5 * sin(ans2);
    pi op; op.x=floor(ax); op.y=floor(ay);
    // show1d(n,ang);
    // cnl(ans);
    cnl(op.x << " "<< op.y);
  }
}
