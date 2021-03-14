// Problem
//

#include <bits/stdc++.h>
using namespace std;
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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000

typedef long long int ll;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
float ncr(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify product
            // division by their gcd saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    return p;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m ,h; cin >> n >> m >> h;
  int arr[m];
  cinp(m,arr);
  int s=accumulate(arr,arr+m,0);
  if(s<n) {cnl(-1); return 0;}
  int k = arr[h-1];
  long double ans=0;
  if (s-k<n-1) ans=1;
  else ans = 1 - ncr(s-k,n-1) / ncr(s-1,n-1);
  cnl(ans);
}
