#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x,n; cin >> x >> n;
  int p[101]={};
  for(int i=0; i<n; i++)
  {
    int a; cin >> a;
    p[a]=1;
  }
  int ans=-1;
  for(int i=0;i<102;i++)
  {
    if(p[x+i]==0) ans=x+i;
    if(p[x-i]==0) ans=x-i;
    if(ans!=-1) break;
  }
  cout << ans << endl;
}
