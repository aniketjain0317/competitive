#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int arr[n];
    for(int i =0; i<n; i++) cin >> arr[i];

    sort(arr,arr+n);
    int mind = INT_MAX, mini = 0;
    int ans[n]={};
    for(int i =0; i<n-1; i++)
      if(arr[i+1]-arr[i]<mind)
        mind = arr[i+1]-arr[i], mini = i;

    ans[0] = arr[mini]; ans[n-1] = arr[mini+1];
    int curr = 1;
    for(int i = mini+2; i<n; i++) ans[curr++] = arr[i];
    for(int i =0; i<mini; i++) ans[curr++] = arr[i];

    for(int i =0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
