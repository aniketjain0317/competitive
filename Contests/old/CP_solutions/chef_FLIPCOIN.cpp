#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,q;
  cin >> n >> q;
  multiset <int> rng;
  rng.insert(0);
  rng.insert(n);
  while(q--)
  {
    int op,str,end;
    cin >> op >> str >> end;
    if (!op)
    {
      rng.insert(str);
      rng.insert(end+1);
    }
    if (op)
    {
      auto begin=lower_bound(rng.begin(),rng.end(),str);
      auto end=lower_bound(rng.begin(),rng.end(),str);
      int c=0;
      for(auto it=rng.begin();it!=rng.end();it++)
      {
        if(*begin==*it) break;
        c++;
      }
      int ans=0;
      if(!c%2) ans-=str;
      else ans-=*begin;
      cout << ans << endl;
      c=0;
      for(auto it=rng.begin();*it!=*end;)
      {
        it++;
        if (*it<=str) c=c;
        int sgn=pow(-1,c++);
        int x=*it;
        ans+=sgn*x; cout << ans << "a" << endl;
      }
      cout << ans << endl;
    }
  }
}
