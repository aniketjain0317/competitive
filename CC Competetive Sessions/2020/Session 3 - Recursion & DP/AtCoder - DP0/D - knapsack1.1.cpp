// WA
// Recursion + Memorization + unordered_map
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001
typedef long long int ll;

// INIT (done globally so it can be used in functions)
unordered_map<ll,ll> dp[101];
ll wt[101]={}, val[101]={};

ll rec(int n, ll w);
int main()
{
  // INPUT
  int n; ll w; cin >> n >> w;
  for(int i=0;  i<n; i++) cin >> wt[i+1] >> val[i+1];

  // OUTPUT
  cout << rec(n,w) << endl;
}

ll rec(int n, ll w)
{
  // base case
  if(!n || !w) return 0;

  // use of the map dp. if it already has been calculated, just return it.
  if(dp[n].find(w)!=dp[n].end()) {cout << n <<"A "<< w <<" "<<dp[n][w]<< endl; return dp[n][w];}

  // if it hasnt beeen calculated yet, do it.
  int a = rec(n-1,w);
  int b = 0;
  if(wt[n]<=w) b = val[n] + rec(n-1,w-wt[n]);
  cout <<"A "<< n << " "<< w << " "<< a <<' '<<b<<' ' << endl;
  for(int i=1;i<=5;i++) {for(int j=1;j<=5;j++) cout << dp[i][j] << " "; cout << endl;}
  dp[n][w]=max(a,b); // or, dp[n].insert(n,max(a,b));

  return dp[n][w];
}
