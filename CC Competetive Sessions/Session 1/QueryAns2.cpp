#include <iostream>
using namespace std;

int main()
{
  int n,q;
  cin >> n >> q;

  int arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];

  // Preprocessing
  int mat[n][n]={};
  for(int p=0; p<n; p++)
  {
    mat[p][p]=arr[p];
    for(int r=p+1; r<n; q++)
    {
      mat[p][r]=mat[p][r-1]+arr[r];
    }
  }

  // query
  for(int i=0;i<q;i++)
  {
    int p,r; cin >> p >> r;
    cout << mat[p][r] << endl;
  }
}
