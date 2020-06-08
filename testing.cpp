255

3

0 1 5

5

0 7 1 2 4

3

4 0 1

7

2 3 6 7 0 5 4

4

7 0 3 5

5

3 6 2 1 4

4

0 4 6 5

5

3 6 4 2 5

5

0 2 3 1 7

5

0 3 7 5 1

4

4 2 6 1

2

6 4

3

5 7 4

1

0

5

5 2 3 4 0

1

7

3

5 0 2

4

5 6 2 0

5

6 7 2 1 3

5

4 2 0 6 3

3

0 6 3

3

2 1 6

7

3 1 7 6 0 2 5

2

6 1

3

7 2 1

4

2 5 1 3

4

2 1 5 4

3

4 2 6

4

3 1 2 0

3

7 0 4

3

2 0 4

5

2 3 6 5 0

5

1 2 3 5 6

5

4 3 7 0 6

4

0 7 6 1

5

7 2 3 6 5

5

1 3 4 5 0

3

3 1 0

2

5 3

6

0 5 3 1 6 4

4

1 4 2 7

6

2 6 5 1 4 7

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

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  test(t)
  {
    int n,k; cin >> n >> k;
    int a[n], b[n]; cinp(n,a); cinp(n,b);
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    int ans=0;
    fr(i,0,k)
    {
      ans += max(a[i],b[i]);
    }
    fr(i,k,n)
    {
      ans+= a[i];
    }
    cnl(ans);
  }
}
