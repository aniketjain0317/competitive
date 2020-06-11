// Problem #6 - GFG - DP Interview Questions
//Solved (simple matrix path dfs)(This is the PRACTICE problem, not the Interview one)

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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test(t)
  {
    int n; cin >> n;
    int mat[n][n];
    fr(i,0,n) fr(j,0,n) cin >> mat[i][j];
    int dp[n][n];
    fr(j,0,n) dp[n-1][j]=mat[n-1][j];
    int mx=0;
    for(int i=n-2;i>=0;i--) fr(j,0,n)
    {
      int a=0,b=0,c=0;
      b=dp[i+1][j];
      if(j) a=dp[i+1][j-1];
      if(n-j-1) c=dp[i+1][j+1];
      dp[i][j]=max({a,b,c})+mat[i][j];
      if(dp[i][j]>mx) mx=dp[i][j];
    }
    cnl(mx);
  }
}
