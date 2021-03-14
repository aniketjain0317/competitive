#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  int arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];

  int x=1;
  for(int i=0; i<n;i++)
  {
    if(arr[i]==x) x++;
  }
  if(x==1) cout << -1 << endl;
  else cout << (n-x+1) << endl;
}
