// Problem 839B - (Contest / 1700)
// Solved (by Tushar)
#include <iostream>
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  int arr[k],sum=0,b=0,odd=0;
  for(int i=0;i<k;i++)
  {
    cin >> arr[i];
    sum+=arr[i];
    if(arr[i]%4==2) b++;
    else if((arr[i]%4)) odd++;
  }

  int x=0;
  if(b>3*n) x=b-3*n;
  if((8*n-sum)>=(odd)) cout << "YES\n";
  else cout << "NO\n";
}
