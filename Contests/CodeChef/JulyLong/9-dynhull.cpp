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
#define showptarr(arr) for(auto pt: arr) {csp("("<<pt.x<<","<<pt.y<<")");} cout<< endl
#define showpt(pt) cnl("("<<pt.x<<","<<pt.y<<")")
#define N 1000
// #define int int16_t;
// #define ll int64_t;

struct Point
{
    int x, y;
};

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<Point> vpi;



Point p0;
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
float distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
   return (o == 2)? -1: 1;
}
vpi convexHull(vpi points, int n)
{
   vpi ans;
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
   swap(points[0], points[min]);
   p0 = points[0];
   qsort(&points[1m<], n-1, sizeof(Point), compare);
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  // Update size of modified array
   }
   if (m < 3) return ans;
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
   for (int i = 3; i < m; i++)
   {
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
   while (!S.empty())
   {
       Point p = S.top();
       ans.pb(p);
       S.pop();
   }
   return ans;
}

double polygonArea(vpi points)
{
    double area = 0.0;
    int n = points.size();
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area / 2.0);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int n; cin >> n;
  vpi arr(n), narr;
  fr(i,0,n) cin >> arr[i].x >> arr[i].y;
  int m; cin >> m;
  vector<double> areav;
  double mini=-1, minid=-1;
  int x =n;
  map<pi,int> orig;
  fr(i,0,n)
  {
    Point pt = arr[i];
    pi pa; pa.fs =pt.x; pa.sn = pt.y;
    orig[pa]=i+1;
  }
  vpi ans;
  double p=0;
  while(true)
  {
    if(x==3) break;
    map<pi,int> orig2;
    fr(i,0,x)
    {
      Point pt = arr[i];
      pi pa; pa.fs =pt.x; pa.sn = pt.y;
      orig2[pa]=i;
    }
    vpi hullo = convexHull(arr,x);
    for(auto pt: hullo)
    {

      pi pa; pa.fs =pt.x; pa.sn = pt.y;
      int i = orig2[pa];
      narr = arr;
      narr.erase(narr.begin()+i);
      if(x==3) {csp("A"); showptarr(narr);}
      vpi hull = convexHull(narr,x-1);
      double harea = polygonArea(hull);
      areav.pb(harea);
      if(mini==-1 || harea<mini) {mini=harea; minid=i;}
      vshow1d(areav);
    }
    areav.clear();
    if(minid!=-1)
    {
      p+=2*mini;
      ans.pb(arr[minid]);
      arr.erase(arr.begin()+minid);
    }
    else
    {
      ans.pb(arr[0]);
      arr.erase(arr.begin());
    }
    x--;
  }
  for(auto x : arr) ans.pb(x);
  for(auto pt: ans)
  {
      pi pa; pa.fs =pt.x; pa.sn = pt.y;
      csp(orig[pa]);
  }
  cout << endl;
  cnl(p);
}
