#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];
  int flag=0;
  for(int i=0;i<pow(2,n);i++)
  {
    int x = i;
    int sum=0;
    for (int j=0;j<n;j++)
    {
      sum+=pow(-1,x%2) * arr[j];
      x=x/2;
    }
    if ((sum%360)==0)
    {
      flag=1;
      break;
    }
  }
  if(flag) cout << "YES";
  else cout << "NO";
}
