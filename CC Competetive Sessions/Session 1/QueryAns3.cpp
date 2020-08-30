#include <iostream>
using namespace std;

int main()
{
  int n,q;
  cin >> n >> q;

  int arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];

  // Preprocessing
  int cumarr[n]={};
  cumarr[0]=arr[0];
  for(int i=1; i<n; i++)
  {
    cumarr[i]=cumarr[i-1]+arr[i];
  }

  // query
  for(int i=0;i<q;i++)
  {
    int p,r; cin >> p >> r;
    int ans = cumarr[r]-cumarr[p]+arr[r];
    cout << ans << endl;
  }
}
