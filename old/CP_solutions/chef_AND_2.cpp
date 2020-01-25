#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int n;
  cin >> n;
  cout << m << n;
  long long int arr[n];
  for (long long int i=0;i<n;i++) cin >> arr[i];
  long long int sum=0,flag=0,power=0,ans=0;
  while(flag<n)
  {
    flag=0;
    long long int count=0;
    for (long long int i=0;i<n;i++)
    {
      if (!arr[i]) {flag++; continue;}
      if (arr[i]%2) count++;
      arr[i]>>=1;
    }
    sum = count*(count-1)/2;
    ans+=pow(2,power)*sum;
    power++;
  }
  cout << ans << endl;
}
