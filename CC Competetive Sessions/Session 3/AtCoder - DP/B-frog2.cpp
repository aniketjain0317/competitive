// AC

#include <bits/stdc++.h>
using namespace std;

#define INF 100001

int main()
{
  // INPUT
  int n; cin >> n;
  int k; cin >> k;
  int arr[n];
  for(int i=0;  i<n; i++) cin >> arr[i];

  // INIT
  int dp[n]={};

  // Base case already done: dp[n-1]=0;


  for(int i=n-2;i>=0;i--)
  {
    int ans[k];
    // For every case: (i+1...i+k)
    for(int j=1; j<=k; j++)
    {
      // ans[j-1] because ans index is (0...j-1)
      if(i+j<n) ans[j-1]= dp[i+j] + abs(arr[i]-arr[i+j]);
      else ans[j-1]=INF;
    }
    dp[i]=*min_element(ans,ans+k);
  }

  // OUTPUT
  cout << dp[0] << endl;
}
