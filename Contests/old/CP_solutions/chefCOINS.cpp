#include <bits/stdc++.h>
using namespace std;
int main() {
	long n;
  vector <int> arr(11);
  int i=0;
  while(cin >> n)
  {
      arr[i]=n;
      if (i>10) break;
      i++;
  }
  int x=*max_element(arr.begin(),arr.end());
  long int dp[x+1];
  dp[0]=0;
  for(long int i=1;i<x+1;i++)
  {
    long int j = dp[i/2] + dp[i/3] + dp[i/4];
    dp[i]=max(i,j);
  }
  for(auto a:arr) cout << dp[a] << endl;
	return 0;
}
