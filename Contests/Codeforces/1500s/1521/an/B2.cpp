#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    auto it = min_element(arr,arr+n);
    ll m = *it, mi = it-arr;
    vector<vector<int>> ans;
    if(mi!=0)
      ans.push_back({1,mi+1,m,m+mi%2});
    for(int i=1; i<n; i++)
    {
      if(i==mi) continue;
      ans.push_back({1,i+1,m,m+i%2});
    }
    cout << ans.size() << endl;
    for(auto &v: ans)
    {
      for(auto &x: v) cout << x << " ";
      cout << endl;
    }
  }
}
