#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1LL<<60;
const int N = 100;


int n;
vvi mat(N,vi(N,INF));
vvi dp(mat);
vvi nxt(N, vi(N,-1));

void floydWarshall()
{
  // init
  dp = mat;
  for(int i = 0; i<n; i++) for(int j = 0; j<n; j++)
  {
    if(dp[i][j]==INF) nxt[i][j]=-1;
    else nxt[i][j] = j;
  }

  // dp
  for(int k = 0; k<n; k++)
    for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++)
        if(dp[i][j]>dp[i][k]+dp[k][j])
          dp[i][j] = dp[i][k]+dp[k][j],
          nxt[i][j] = nxt[i][k];

  // Negative Cycle Detection
  for(int k = 0; k<n; k++)
    for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++)
        if(dp[i][j]>dp[i][k]+dp[k][j])
          dp[i][j] = -INF,
          nxt[i][j] = -1;
}

vi path(int s, int d)
{
  vi ans;
  if(dp[s][d]==INF) return {-1};
  if(dp[s][d]==-INF)  return {-2};

  int i = s, j = d;
  while(nxt[i][j]!=-1)
  {
    ans.push_back(i);
    i = nxt[i][j];
  }
  ans.push_back(j);
  return ans;
}

int32_t main()
{
  int n; cin >> n;
  for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) cin >> mat[i][j];
  floydWarshall();

}
