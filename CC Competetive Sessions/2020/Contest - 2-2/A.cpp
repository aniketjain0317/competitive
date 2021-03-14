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
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}

void multiply(ll a[3][3], ll b[3][3])
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    ll mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j]= am(mul[i][j], mm(a[i][k],b[k][j]));
        }
    }

    // storing the multiplication result in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}

ll power(ll F[3][3], ll n)
{
    ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};

    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if (n==1)
        return (mm(4,F[0][0]) + mm(2,F[0][1]) + mm(1,F[0][2]))%INF;

    power(F, n/2);

    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);

    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    return (mm(4,F[0][0]) + mm(2,F[0][1]) + mm(1,F[0][2]))%INF;
}
ll findNthTerm(ll n)
{

    ll F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;

    //Base cases
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    if(n==3)
        return 4;
    return power(F, n-2);
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
    ll n; cin >> n;
    cnl(findNthTerm(n));
  }
}
