#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<pair<int,int>> arr;
  int n,m; cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    int c,b; cin >> c >> b;
    pair<int,int> p1(c,b);
    arr.push_back(p1);
  }
  sort(arr.begin(),arr.end());

  ll ans=0, pz=0;
  for(int i=0;i<n;i++)
  {
    if(pz+arr[i].second<m) ans+=arr[i].first*arr[i].second;
    else {ans+=arr[i].first*(m-pz); break;}

  }
}
