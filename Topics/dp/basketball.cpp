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
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  int n;
  ll h1[n]; ll h2[n]; cinp(n,h1); cinp(n,h2);
  ll dp1[n],dp2[n];
  dp1[0]=h1[0];
  dp2[0]=h2[0];
  fr(i,1,n)
  {
    dp1[i]=max(dp1[i-1],(dp2[i-1]+h1[i]));
    dp2[i]=max(dp2[i-1],(dp1[i-1]+h2[i]));
  }

  cout << max(dp1[n-1],dp2[n-1]);
}
