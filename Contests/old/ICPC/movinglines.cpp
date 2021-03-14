#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,flag=0;
    cin >> n;
    map <int,vector<pair<int,int>>> h;
    for(int i=0;i<n;i++)
    {
      int l,r,v;
      cin >> l >> r >> v;
      h[v].push_back({l,r});
    }
    for (auto mappair:h)
    {
      map <int,int> count;
      for (auto vpair:mappair.second)
      {
          for(int i=vpair.first;i<=vpair.second;i++)
          {
            count[i]+=1;
            if (count[i]==3) {flag=1; break;  break; break;}
          }
      }
    }
    flag? cout << "NO" : cout << "YES";
    cout << endl;
  }
}
