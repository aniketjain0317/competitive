#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, kk;
const int N = 51;
const int MOD = 1000000007;
int dp[N][N][61]={};

// all possible paths starting from i of length x
map<int,int> mp[N];
int rec(int i, int x)
{
  if(mp[i].count(x)) return mp[i][x];
  int k = 0;
  while((1LL<<k) <= x) k++; k--;
  int y = x-(1LL<<k), ans = 0;
  for(int j  = 0; j<n; j++)
  {
    int val = dp[i][j][k];
    if(!val) continue;
    if(y) val = (val*rec(j,y))%MOD; // rec(j,0)=1;
    ans = (ans+val)%MOD;
  }

  mp[i][x]=ans;
  return ans;
}


int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> kk;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
      cin >> dp[i][j][0];

  for(int k =1; k<=60; k++)
    for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++)
        for(int l = 0; l<n; l++)
          dp[i][j][k] = (dp[i][j][k] + (dp[i][l][k-1]*dp[l][j][k-1])%MOD)%MOD;

  int ans = 0;
  for(int i =0; i<n; i++) ans = (ans + rec(i,kk))%MOD;
  cout << ans << endl;
}
