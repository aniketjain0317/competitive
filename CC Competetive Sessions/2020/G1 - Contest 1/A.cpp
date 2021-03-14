#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i; cin >> i;
  int j;
  if(i%111==0) j=i;
  else j=(i/111+1)*111;
  cout << j << endl;
}
