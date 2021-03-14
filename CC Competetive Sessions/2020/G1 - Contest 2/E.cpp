#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s; cin >> s;
  int ans=0, curr=0;
  for(auto c:s)
  {
    if(c=='A' || c=='C' || c=='G' || c=='T') curr++;
    else
    {
      ans=max(ans,curr);
      curr=0;
    }
  }
  if(curr) ans=max(ans,curr);

  cout << ans << endl;
}
