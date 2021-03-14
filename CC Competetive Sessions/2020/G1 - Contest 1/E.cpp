#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n; cin >> n;
  string str[n];
  for(int i=0; i<n; i++)
  {
    cin >> str[i];
  }
  for(int i=0; i<n; i++)
  {
    sort(str[i].begin(),str[i].end());
  }

  int ans=0, cnt=0;
  sort(str,str+n);

  for(int i=1; i<n; i++)
  {
    if(str[i]==str[i-1]) cnt++;
    else if(cnt)
    {
      ans += (cnt*(cnt+1))/2;
      cnt=0;
    }
  }
  if(cnt) ans+=(cnt*(cnt+1))/2;
  //
  // map<string,int> mp;
  // for(int i=0; i<n; i++) mp[str[i]]++;
  // for(auto p: mp)
  // {
  //   if(p.second>1)
  //     ans+= (p.second*(p.second-1))/2;
  // }

  cout << ans << endl;
}
