#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; cin >> t;
  while(t--)
  {
    int k; cin >> k;
    vector<int> ansx;
    vector<int> ansy;
    for(int x=k+1; x<=2*k; x++)
    {
      if((x*k)%(x-k)==0)
      {
        int y=(x*k)/(x-k);
        ansx.push_back(x);
        ansy.push_back(y);
      }
    }
    int sz = ansx.size();
    cout << sz << endl;
    for(int i=0; i<sz;i++)
    {
      cout << ansy[i] << " " << ansx[i] << endl;
    }
  }
}
