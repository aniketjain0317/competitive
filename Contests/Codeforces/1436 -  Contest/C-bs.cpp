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
int MOD = 1e9+7;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int a=0,b=0,c=0;

int bs(int n, int x, int pos)
{
  int left =0;
  vi avi(n,0);
  int right = avi.size();
  while(left<right)
  {
    int middle = (left+right)/2;
    // cnl("lmr "<<left<<" "<<middle<<" "<<right);
    if(middle<=pos)
    {
      if(middle<pos) a+=1;
      left = middle+1;
    }
    else if (middle>pos)
    {
      b+=1;
      right = middle;
    }
  }
  if(left>0 && left-1==pos) return pos;
  else return -1;
}


long long mm(long long a,
                            long long b,
                            long long mod)
{
    long long res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;
    if(a==0) return 0;
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }

    return res;
}

long long calcP(int n, int r)
{
  ll ans = 1;
  frr(i,n-r+1,n) ans = (ans*i)%MOD;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,x,pos; cin >> n >> x >> pos;
  bs(n,x,pos);
  // cnl("AB "<<a<<" "<<b);
  ll ans = 1;
  if(x-1<a) ans=0;
  if(n-x<b) ans=0;
  ans =  mm(ans, calcP(x-1,a),MOD);
  // cnl(ans);
  ans = mm(ans, calcP(n-x,b), MOD);
  // cnl(ans);
  frr(i,1,n-a-b-1) ans = (ans*i)%MOD;
  cnl(ans);
}
