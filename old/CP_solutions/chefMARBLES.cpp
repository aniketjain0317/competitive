#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

int main()
{
  int t;
  cin >> t;
  int size = t;
  vector <int> arrN;
  vector <int> arrK;
  while(t--)
  {
    int n,k;
    cin >> n >> k;
    arrN.push_back(n);
    arrK.push_back(k);
  }

  int x = *max_element(arrN.begin(),arrN.end());
  uint64_t fact[x+1];
  fact[0]=1;
  for (int i=1;i<x+1;i++) fact[i]=i*fact[i-1];

  for (int i=0;i<size;i++)
  {
    int n=arrN[i],k=arrK[i];
    cout << (fact[n-1]/(fact[k-1]*fact[n-k])) << endl;
  }
}
