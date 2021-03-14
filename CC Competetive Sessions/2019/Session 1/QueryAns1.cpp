#include <iostream>
using namespace std;

int main()
{
  int n,q;
  cin >> n >> q; // Alternatively, use scanf("%d %d", &n,&q);

  int arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];

  for(int i=0;i<q;i++)
  {
    int p,q; cin >> p >> r;

    int ans=0;
    for(int j=p; j<=r; j++) ans+=arr[j];

    cout << ans << endl; // Alternatively, use cout << ans << "\n";
  }
}
