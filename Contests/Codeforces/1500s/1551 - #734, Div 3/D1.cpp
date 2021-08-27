#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n,m,k; cin >> n >> m >> k;
    int k2 = n*m - 2*k;
    if(n%2==1) k-=(m/2);
    if(k<0 || k%2==1) cout << "NO" << endl;
    else if(m%2==1 && k2<n) cout << "NO" << endl;
    else
    {
      cout << "YES" << endl;
      int id = 1;
      int mat[n+5][m+5]={};
      int nn = n;
      if(n%2==1) for(int j=0; j<m; j+=2) mat[n-1][j]=id, mat[n-1][j+1]=id++;
      if(n%2==1) n--;
      for(int j=0; j<m; j+=2)
      {
        if(!k) break;
        for(int i = n-1; i>=0; i--)
        {
          mat[i][j]=id, mat[i][j+1]=id++, k--;
          if(!k) break;
        }
      }
      for(int j=0; j<m; j++) for(int i = 0; i<n; i+=2)
      {
        if(mat[i][j] || mat[i+1][j]) break;
        mat[i][j] = id, mat[i+1][j]=id++;
      }
      n = nn;

      char ans[n+5][m+5]={};
      for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) if(!ans[i][j])
      {
        char x = 'a';
        if(mat[i][j]==mat[i][j+1])
        {
          while((i && ans[i-1][j]==x) || (j && ans[i][j-1]==x) || (i && ans[i-1][j+1]==x) || (ans[i][j+2]==x)) x++;
          ans[i][j]=x, ans[i][j+1]=x;
        }
        else
        {
          while((i && ans[i-1][j]==x) || (j && ans[i][j-1]==x) || (j && ans[i+1][j-1]==x) || (ans[i+2][j]==x)) x++;
          ans[i][j]=x, ans[i+1][j]=x;
        }
      }
      for(int i = 0; i<n; i++) {for(int j = 0; j<m; j++) cout << ans[i][j]; cout << endl;}

    }
  }
}
