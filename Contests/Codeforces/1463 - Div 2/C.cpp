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
  #define all(v) v.begin(),v.end()
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


  typedef long long ll;
  typedef vector<int> vi;
  typedef vector<vi> vvi;

  ll INF =  1000000005;
  double dt(int t, vi pt, vi px)
  {
    int pi = upper_bound(all(pt), t)-pt.begin();
    double t1 = pt[pi-1];
    double t2 = pt[pi];
    if(t1==t) return px[pi-1];
    double x2 = px[pi];
    if(t1==t2) {t2=pt[pi+1]; x2=px[pi+1];}
    double x0 = ((t-t1)/(t2-t1))*(x2-px[pi-1]) + px[pi-1];
    return x0;
  }


  int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("myans.txt","w",stdout);
    // freopen("input.txt","r",stdin);
    test(t)
    {
      int n; cin >> n;
      int art[n+1], arx[n];
      art[n]=INF;
      fr(i,0,n) cin >> art[i] >> arx[i];

      vi pt, px;
      pt.pb(0); px.pb(0);
      int c=0, p=0;
      fr(i,1,n)
      {
          if(art[i]-art[c]>=abs(arx[c]-p))
          {
            pt.pb(art[c]); px.pb(p);
            pt.pb(art[c]+abs(arx[c]-p));
            px.pb(arx[c]);
            p=arx[c];
            c=i;
          }
      }
      pt.pb(art[c]); px.pb(p);
      pt.pb(art[c]+abs(arx[c]-p)); px.pb(arx[c]);
      pt.pb(INF); px.pb(arx[c]);
      int ans=0;
      // vshow1d(pt);
      // vshow1d(px);
      fr(i,0,n)
      {
        int pi = upper_bound(all(pt), art[i])-pt.begin();
        int x0 = ceil(dt(art[i],pt,px));
        int mx=ceil(x0), mn = mx;
        int x1 = floor(dt(art[i+1],pt,px));
        if(i==n-1) x1 = px[px.size()-1];
        mx=max(mx,x1);
        mn=min(mn,x1);
        // csp("THIS "<<i);
        // csp(x0); csp(x1);
        // csp(arx[i]);
        if(mx>=arx[i] && mn<=arx[i]) {ans++;}
        // cnl(" ");
      }
      // csp("AAAAAAAAAAA");
      cnl(ans);
    }
  }
