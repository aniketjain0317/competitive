// Problem
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; cin >> t;
  while(t--)
  {
    string s; cin >> s;
    int a = s[0] - 48;
    int b = s.size();
    int ans = (a-1)*10 + b*(b+1)/2;
    cout << ans << endl;
  }
}
