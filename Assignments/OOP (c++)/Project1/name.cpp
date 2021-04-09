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

class Name
{
private:
  string m_fname;
  string m_mname;
  string m_lname;
public:
  Name(string str)
  {
    // constructor is only used for calling the tokenizer and storing the values now
    vector<string> v = tokenizeString(str);
    // error checking that v.size()>=3 should be present here
    assert(v.size()>=3);
    m_fname= v[0];
    m_mname = v[1];
    m_lname = v[2];
  }

  // function to split a string (idk a native function so made my own)
  vector<string> tokenizeString(string str)
  {
    vector<string> ans;
    string a="";
    for(auto c: str)
    {
      if(c==' ') { ans.pb(a); a=""; }
      else a=a+c;
    }
    if(a!="") ans.pb(a);
    return ans;
  }

  // string get_fname() return m_fname;     THIS DOESNT WORK??? WHY? (error: cannot return named values)
  string get_fname() {return m_fname;}
  string get_mname() {return m_mname;}
  string get_lname() {return m_lname;}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  Name aniket("Aniket RandomWord Jain");
  cnl(aniket.get_lname());
}
