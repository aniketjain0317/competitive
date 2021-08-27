#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pi;
int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int vals[n][6]={};
      for(int i = 0;i<n; i++)
      {
        string s; cin >> s;
        for(auto c: s) vals[i][c-'a']++, vals[i][5]++;
      }
    int ans = 0;
    for(int c = 0; c<5; c++)
    {
      vector<int> new_val;
      int mx = 0, curr=0;
      for(int i = 0; i<n; i++) new_val.push_back((2*vals[i][c] - vals[i][5]));
      sort(new_val.begin(), new_val.end(), greater<int>());
      for(; mx<n; mx++)
      {
        curr+=new_val[mx];
        if(curr<=0) break;
      }
      ans = max(ans, mx);
    }
    cout << ans << endl;
  }
}
