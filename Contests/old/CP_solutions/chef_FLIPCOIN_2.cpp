#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,q;
  cin >> n >> q;
  vector <int> v;
  v.push_back(0);
  v.push_back(n);
  while(q--)
  {
    int op,str,end;
    cin >> op >> str >> end;
    if (op)
    {
      auto start = lower_bound(v.begin(),v.end(),str);
      auto stop = lower_bound(v.begin(),v.end(),end+1);
      int ipsn = start-v.begin(), fpsn=stop-v.begin();

      int ans=0;
      if (ipsn%2) ans-=v[ipsn++];
      else ans-=str;


      int sc=0, sgn;
      for(int i=ipsn;i<fpsn;i++,sc++)
      {
        sgn=pow(-1,sc);
        int val=v[i];
        ans+=sgn*val;
      }
      if (sgn==-1) ans+=(end+1);
      cout << ans << endl;
    }
    if (!op)
    {
      auto ptr1=lower_bound(v.begin(),v.end(),str);
      auto ptr2=lower_bound(v.begin(),v.end(),end+1);
      int p1=ptr1-v.begin(), p2=ptr2-v.begin();
      v.insert(v.begin()+p2,end+1);
      v.insert(v.begin()+p1,str);
    }

  }
}
