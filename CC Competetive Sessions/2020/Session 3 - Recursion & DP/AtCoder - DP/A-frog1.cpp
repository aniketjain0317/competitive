// AC

#include <bits/stdc++.h>
using namespace std;

#define INF 100005

int main()
{
  // INPUT
  int n; cin >> n;
  int arr[n];
  for(int i=0;  i<n; i++) cin >> arr[i];

  // INIT
  int dp[n]={};

  // Base case:
  dp[0]=0;
  dp[1]=dp[0]+abs(arr[i]-arr[i-1]);


  for(int i=2;i<n;i++)
  {
    // dp[i] is the min cost of the subsystem arr[0...i]
    // 30 10 60 10 60 50
    int a = dp[i-1] + abs(arr[i]-arr[i-1]);
    int b = dp[i-2] + abs(arr[i]-arr[i-2]);
    dp[i]= min(a,b);
  }

  // OUTPUT
  cout << dp[n-1] << endl;
}
// n <- min(dp(n-1)+diff(n,n-1), dp(n-2)+diff(n,n-2))
