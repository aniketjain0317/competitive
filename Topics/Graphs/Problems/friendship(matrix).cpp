//Problem 771A - Codeforces (dfs and similar / 1500)
//RTE on Test 10 (probably the matrix dimensions are too big)
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m,flag=0;
  cin >> n >> m;
  bool matrix[n][n]={};
  for(int i=0;i<m;i++)
  {
    int t1, t2;
    cin >> t1 >> t2, t1--,t2--;
    matrix[t1][t2]=1;
    matrix[t2][t1]=1;
  }
  for(int i=0;i<n;i++) matrix[i][i]=1;

  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(matrix[i][j])
      {
        bool truth = equal(&matrix[i][i+1],&matrix[i][n],&matrix[j][i+1]);
        if(!truth) {flag=1; break;}
      }
    }
    if(flag) break;
  }

  if(!flag) cout << "YES\n";
  else cout << "NO\n";
}
