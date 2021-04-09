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
  test(t)
  {
    int n, k; cin >> n >> k;
    int arr[k+1]={}; fr(i,1,n+1) read(arr[i]);
a
    int dp[k+1];
    dp[1]=arr[1];
    int num[k+1]={};
    frr(i,1,k) {dp[i]=arr[i]; num[i]=1; if(dp[i]==-1) dp[i]=10000;}
    frr(i,2,k)
    {
      frr(j,1,i/2)
      {
        if(dp[j]==10000||dp[i-j]==10000)  continue;
        int x1=dp[j]+dp[i-j];
        int n1=num[j]+num[i-j];
        if(x1<dp[i])
        {
          dp[i]=x1;
          num[i]=n1;
        }
      }
    }
    if(num[k]>n) cnl(-1);
    else cnl(dp[k]);
  }
}
