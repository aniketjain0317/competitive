#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  map <int, int> arr;
  for (int i=0;i<n;i++)
  {
    cin >> temp;
    arr[temp]+=1;
  }

  sort(arr,arr+n);
  int ans=1;
  for (int i =0; i<n; i++)
  {
    int s=1;
    while ((arr[s+i]-arr[i]<=5) && (s+i)<n) s++;
    if(s>ans) ans=s;
    if(ans>n-2) break;
    if (ans == n-2)
    {
      int s=1;
      while ((arr[n-1]-arr[n-s]<=5) && (n-s)>=0) s++;
      if(s>ans) ans=s;
      break;
    }
  }
  cout << ans;
}
