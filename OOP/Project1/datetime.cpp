// Problem
//

#include <bits/stdc++.h>
using namespace std;



// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
//
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
//
// #endif  /* _USE_MATH_DEFINES */


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
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef unsigned char uc;

enum units {YEAR, MONTH, DAY, HOUR, MINUTE, SECOND, MAX_VAL};


class Datetime
{
private:
  int m_datetime;
  vi m_data;
  const int blen[6]={7,4,5,5,6,5};
public:
  Datetime(int t)
  {
    m_datetime=t;
    m_data = deconstructInt(t);
    verifyData(m_data);
  }

  Datetime(vi data)
  {
    verifyData(data);
    m_datetime = constructInt(data);
  }

  vi deconstructInt(int t)
  {
    vi ans(6,0);
    std::bitset<32> x(t);
    int start=32;
    fr(i,0,6)
    {
      bitset<8> y(0);
      start-=blen[i];
      fr(j,0,blen[i]) y[j]=x[start+j];
      ans[i]=y.to_ulong();
    }
    return ans;
  }

  int constructInt(vi data)
  {
    bitset<32> x(0);
    int start=32;
    fr(i,0,6)
    {
      bitset<8> y(data[i]);
      start-=blen[i];
      fr(j,0,blen[i]) x[start+j]=y[j];
    }
    // cout << x << endl;
    int ans = x.to_ulong();
    return ans;
  }

  int verifyData(vi data)
  {
    assert(data.size()==6);
    assert(data[YEAR]<=127 && data[YEAR]>=0);
    assert(data[MONTH]<=12 && data[MONTH]>=1);
    assert(data[DAY]<=31 && data[DAY]>=0);
    assert(data[HOUR]<=23 && data[HOUR]>=0);
    assert(data[MINUTE]<=59 && data[MINUTE]>=0);
    assert(data[SECOND]<=29 && data[SECOND]>=0);
    return 1;
  }

  int change_data(int val, int unit)
  {
    if(unit>=MAX_VAL) return -1;
    vi newdata(m_data); newdata[unit]=val;
    verifyData(newdata);
    int ans = constructInt(newdata);

    m_data=newdata;
    m_datetime=ans;
    return ans;
  }

  int get_int() {return m_datetime;}
  vi get_data() {return m_data;}
  void print_date() {cout << m_data[DAY] << "/" << m_data[MONTH] << "/" << m_data[YEAR]+1980<< endl;}
  void print_time() {cout << m_data[HOUR] << ":" << m_data[MINUTE] << ":" << 2 * m_data[SECOND] << endl;}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  // 1/4/2005 10:31:44
  Datetime dt(0x328153F6);
  dt.print_date();
  dt.change_data(9,MONTH);
  dt.print_date();
  dt.print_time();
  cnl(0x328153F6);
  cnl(dt.get_int());
}
