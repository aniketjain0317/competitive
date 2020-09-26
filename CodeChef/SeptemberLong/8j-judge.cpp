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


  int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("judge.txt","w",stdout);
    freopen("input.txt","r",stdin);
    int t;
    {
        // ifstream cin("input.txt");
        cin >> t;
    }
    fr(tno,0,t)
    {
      int n;
      {
        // ifstream cin("input.txt");
        cin >> n;
      }
      ll arrx[n]={};
      ll arry[n]={};
      ll vecx[n]={}, vecy[n]={};
      double ang[n]={};
      {
          // ifstream cin("input.txt");
          fr(i,0,n) {cin >> arrx[i] >> arry[i];}
          // cnl("A: "<<arrx[i]<<" "<<arry[i]);}
      }

      fr(i,0,n)
      {
        vecx[i]=(arrx[(i+1)%n]-arrx[i]);
        vecy[i]=arry[(i+1)%n]-arry[i];
        ang[i]=atan2(vecy[i],vecx[i]) * 180 / M_PI;
      }
      // spi ls[n], ls2[n];
      // fr(i,0,n-1)
      // {
      //   ls[i]=(rng(arrx[i],arry[i],arrx[i+1],arry[i+1]));
      //   ls2[i]=(rng(arrx[i+1],arry[i+1],arrx[i],arry[i]));
      // }
      // ls[n-1]=rng(arrx[n-1],arry[n-1],arrx[0],arry[0]);
      // ls2[n-1]=rng(arrx[0],arry[0],arrx[n-1],arry[n-1]);

      ll ansx=0, ansy=0;
      {
          // ifstream cin("input.txt");
          cin >> ansx >> ansy;
          if(!ansx && !ansy) continue;
          double ang=atan2(ansy,ansx) * 180 / M_PI;
          cnl(ang);
      }
      int cs=0;
      int sgn=0;
      fr(i,0,n)
      {
        ll ch = ansx*vecx[i] + ansy*vecy[i];
        if(!ch)
        {
          cs=-1;
          csp(-1);
          csp(tno);
          csp(ansx); cnl(ansy);
          csp("i: "<<i);
          break;
        }
        bool a = (ch<0);
        csp(a);
        if(a==sgn) continue;
        else {sgn=a; cs+=1;}
        if(cs==3)
        {
          csp(3);
          csp(tno);
          csp(ansx); cnl(ansy);
          break;
        }
      }
      if(cs!=3) cout << endl;
    }
  }
