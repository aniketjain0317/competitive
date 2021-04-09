//Problem 771A - Codeforces (dfs and similar / 1500)
//Solved (was able to solve it only using list, not matrix)
#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,m,flag=0;
  cin >> n >> m;
  vector <int> list[n];
  for(int i=0;i<m;i++)
  {
    int t1, t2;
    cin >> t1 >> t2, t1--, t2--;
    list[t1].push_back(t2);
    list[t2].push_back(t1);
  }
  for(int i=0;i<n;i++)
  {
    list[i].push_back(i);
    sort(list[i].begin(),list[i].end());
  }

  for(int i=0;i<n;i++)
  {
    for( int linked: list[i])
    {
      if(linked>i)
      {
        bool truth = list[i].size()==list[linked].size() && equal(list[i].begin(),list[i].end(),list[linked].begin());
        if(!truth) {flag=1; break;}
      }
    }
    if(flag) break;
  }

  if(!flag) cout << "YES\n";
  else cout << "NO\n";
}
