// Problem #6 - GFG - DP Interview Questions
//Solved (2d dp problem)(This is the Interview problem, not the PRACTICE one)

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
    ainp(n,arr);
    int s; cin >> s;
    int dp[s+1][n+1]={};
    fr(i,0,n)
    {
      frr(i,1,s) frr(j,1,n)
      {

        if(j==1) dp[i][j]=(arr[j-1]==i);
        else if(i==1) dp[i][j]=(dp[i][j-1]||(arr[j-1]==i));
        else
        {
          // int a=(arr[j-1]==i);
          // int b=dp[i][j-1];
          // int c=(arr[j-1]<i);
          // int d=dp[i-arr[j-1],j-1];
          dp[i][j] = (arr[j-1]==i) || (dp[i][j-1]==1) || ((arr[j-1]<i)&&(dp[i-arr[j-1]][j-1]));
          // if(i==5&&j==3) csp(a); csp(b); csp(c); cnl(d);
        }
      }
    }
    frr(i,1,s)
    {
      csp(i);
      frr(j,1,n)
      {
        csp(dp[i][j]);
      }
      cnl(' ');
    }
  }
}
