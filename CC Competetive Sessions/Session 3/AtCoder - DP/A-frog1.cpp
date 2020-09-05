// AC

#include <bits/stdc++.h>
using namespace std;

#define INF 1e5+1

int main()
{
  // INPUT
  int n; cin >> n;
  int arr[n];
  for(int i=0;  i<n; i++) cin >> arr[i];

  // INIT
  int dp[n]={};

  // Base case already done: dp[n-1]=0;


  for(int i=n-2;i>=0;i--)
  {
    // dp[i] is the min cost of the subsystem arr[i...n-1]
    // 30 10 60 10 60 50
    int a = dp[i+1] + abs(arr[i]-arr[i+1]);
    int b = INF;                           // To make sure dp[i]=a when i=n-2
    if(i+2<n) b = dp[i+2] + abs(arr[i]-arr[i+2]);
    dp[i]= min(a,b);
  }

  // OUTPUT
  cout << dp[0] << endl;
}
