#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector <pair<string,bool>> arr(n);
    for(int i=0;i<n;i++)
    {
      string tempString;
      bool tempBool;
      cin >> tempString >> tempBool;
      arr[i].first=tempString;
      arr[i].second=tempBool;
    }
    map<pair<string,bool>, unsigned int> h;
    for (auto const & x : arr)
    {
      ++h[x];
    }
    int sum=0;
    for (auto const & p : h)
    {
      if (!h[{p.first.first,p.first.second?0:1}]) sum+=p.second;
      else if (p.first.second==0)
      {
        sum+=max(p.second,h[{p.first.first,1}]);
      }
    }
    cout << sum << endl;
  }
}
