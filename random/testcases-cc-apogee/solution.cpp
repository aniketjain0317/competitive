#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("input4","r",stdin);
  freopen("output4","w",stdout);
  int n,m; cin >> n >> m;
  int arr[n][m], left[n][m], right[n][m];
  for(int i=0; i<n; i++) for(int j=0; j<m; j++)
  {
    char c; cin >> c;
    arr[i][j]=c-'0';
  }

  int fl[n]={}, fr[n]={};
  for(int i=0; i<n; i++)
  {
    int f = 0, ls = -1;
    for(int j=0; j<m; j++)
    {
      if(arr[i][j])
      {
        if(!f++) fl[i]=j;
        ls = j;
      }
    }
    if(!f)
    {
      cout << -1 << endl;
      return 0;
    }
    fr[i]=ls;
  }

  for(int i=0; i<n; i++)
  {
    int prev = fr[i]-m;
    for(int j=0; j<m; j++)
    {
      if(arr[i][j]) prev = j;
      left[i][j] = j-prev;
    }
  }
  for(int i=0; i<n; i++)
  {
    int nxt = fl[i]+m;
    for(int j=m-1; j>=0; j--)
    {
      if(arr[i][j]) nxt = j;
      right[i][j] = nxt-j;
    }
  }

  int ans = 100000000;
  for(int j=0; j<m; j++)
  {
    int curr=0;
    for(int i=0; i<n; i++)
      curr+=min(left[i][j],right[i][j]);
    ans = min(ans,curr);
  }

  cout << ans << endl;
}
