#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int t; cin >> t;
  while(t--)
  {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    if(b>=0) {cout << n*(a+b) << endl; continue;}
    int cnt[2] = {};
    s.push_back('.'); reverse(s.begin(), s.end());
    for(int i = 1; i<=n; i++)
      if(s[i]!=s[i-1])
        cnt[s[i]-'0']++;

    int ans = min(cnt[0]+1, cnt[1]+1)*b + n*a;
    cout << ans << endl;
  }
}
