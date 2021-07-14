#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int arr[n], sm=0;
    for(int i=0; i<n; i++) cin >> arr[i], sm+=arr[i];
    // cout << "AAAAAAAAAAA ";
    if(sm<n) cout << 1 << endl;
    else cout << sm-n << endl;
  }
}
