// AC (+0)
// Silly Mistake: using 1-index in pref, but 0-index in s.
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  string s; cin >> s; int n = s.size(); s.push_back('x');
  int pref[n+1]={};
  for(int i = 1; i<=n; i++)
  {
    pref[i]=pref[i-1];
    if(s[i-1]==s[i]) pref[i]++;
  }
  int m;  cin >> m;
  while(m--)
  {
    int l,r; cin >> l >> r;
    cout << pref[r-1]-pref[l-1] << endl;
  }
}
