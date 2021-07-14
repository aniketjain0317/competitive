#include <bits/stdc++.h>
using namespace std;

#define int long long
#define am(a,b)  (a+b+MOD+MOD)%MOD;
#define mm(a,b)  ((a*b)%MOD+MOD)%MOD;

const int MOD = 1000000007;


int32_t main()
{
  int h,w; cin >> h >> w;
  int mat[h+1][w+1]={};
  for(int i = 1; i<=h; i++) for(int j=1; j<=w; j++)
  {
    char c; cin >> c;
    mat[i][j]=(c=='.');
  }
  int dp[h+1][w+1]={}; dp[1][1]=1;
  for(int i = 1; i<=h; i++) for(int j=1; j<=w; j++)
  {
    if(mat[i-1][j]) dp[i][j]=am(dp[i][j],dp[i-1][j]);
    if(mat[i][j-1]) dp[i][j]=am(dp[i][j],dp[i][j-1]);
  }
  cout << dp[h][w] << endl;
}
