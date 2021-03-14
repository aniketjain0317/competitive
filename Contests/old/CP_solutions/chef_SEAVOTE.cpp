#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t; cin >> t; while(t--)
  {
    int n,c=0,sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
      int temp; cin >> temp;
      if (temp) sum+=temp;
      else c++;
    }
    if ((sum>=100)&&((sum-n+c)<100)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
