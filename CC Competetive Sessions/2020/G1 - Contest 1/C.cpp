#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k; cin >> n >> k;
  int p[n+1]={};
  for(int i=0; i<k; i++)
  {
    int d; cin >> d;
    for(int j=0; j<d;j++)
    {
      int a; cin >> a;
      p[a]=1;
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(p[i]==0) ans++;
  }
  cout << ans << endl;
}
