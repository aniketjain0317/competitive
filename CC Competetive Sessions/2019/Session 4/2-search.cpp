#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[6] = {10,20,5,15,30,-10};
  sort(arr,arr+6);
  // {-10,5,10,15,20,30}
  //  { 0,1, 2, 3, 4, 5}

  // cout << binary_search(arr,arr+6,30) << endl;

  vector<int> v(arr,arr+6);
  // already sorted


  // lower_bound: (5,15] gives i=3
   // upper_bound: [5,15) gives i=3, 15 gives i=4
  auto ptr = lower_bound(arr,arr+6,15);
  cout << ptr - arr << endl;
}
