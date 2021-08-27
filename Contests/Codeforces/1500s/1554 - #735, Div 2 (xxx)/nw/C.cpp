#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n,m; cin >> n >>m;
    if(n>m)
    {
      cout << 0 << endl;
      continue;
    }
    int ans = 0;
    for(int i = 32; i>=0; i--)
    {
      int k = 1LL<<i;
      if((m&k) && (!(n&k))) ans |=k;
      else if((!(m&k)) && (n&k)) break;
    }
    if((n^ans) <= m)
    {
      int adn = 1;
      while(m&1) m>>=1, adn<<=1;
      ans |= adn;
      adn-=1; adn=~adn;
      ans &= adn;
    }
    cout << ans << endl;
  }
}
