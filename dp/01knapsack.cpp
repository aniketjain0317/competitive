// Problem #9 - GFG - DP Interview Questions
//Solved (standard 2d dp array problem)

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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
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
    int n;int w; cin >> n >> w;
    int wt[n]={}; int val[n]={};
    cinp(n,val); cinp(n,wt);
    int dp[n][w+1]={};
    fr(i,0,n)
    {
      frr(j,1,w)
      {
        int a=0;
        if(i>0) a=dp[i-1][j];
        int b=0;
        if(j>wt[i]&&i) b = dp[i-1][j-wt[i]]+val[i];
        int c=0;
        if(j==wt[i]) c=val[i];
        dp[i][j]=max({a,b,c});
      }
    }
    int ans=0;
    frr(j,1,w) if(dp[n-1][j]>ans) ans=dp[n-1][j];
    cnl(ans);
  }
}
