#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
     int m,k;
    string num;
    cin >> k >> m;
    cin >> num;
     int len = num.size();
     // int ans = (num[0] - '0') % m;
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
      // cout << ans << " ";
      ans=(ans * k) % m;
      ans=(ans + num[i] - '0') % m;
      cout << ans << " ";
    }
    cout << endl;
    // cout << ans << " " << endl;
  }
}
