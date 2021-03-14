// AC

#include <bits/stdc++.h>
using namespace std;

#define INF 100005

int main()
{
  // INPUT
  int n; cin >> n;
  int arr[n][3];
  for(int i=0;  i<n; i++)
  {
    for(int k=0; k<3; k++) cin >> arr[i][k];
  }


  // INIT
  int dp[n][3]={};

  // Base case
  dp[0][0]=arr[0][0];
  dp[0][1]=arr[0][1];
  dp[0][2]=arr[0][2];


  for(int i=1;i<n;i++)
  {
    for(int k=0;k<3;k++)
    {
      // dp[i][k] is the score when we choose the kth activity on the ith day
      int a = dp[i-1][(k+1)%3];
      int b = dp[i-1][(k+2)%3];
      dp[i][k]=arr[i][k] + max(a,b);
    }
  }

  // OUTPUT
  int ans = *max_element(dp[n-1],dp[n-1]+3);
  cout << ans << endl;
}
