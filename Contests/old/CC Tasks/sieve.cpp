// Used the Sieve of Eratosthenes method to generate prime factors of large test cases
// input t >> number of test cases.
// then input t test cases all less than a known value n
#include <bits/stdc++.h>
using namespace std;
vector<int> numbers;
void genPrimes(int);
int main()
{
  int n=10000;
  int t;
  cin >> t;
  numbers.assign(n,0);
  genPrimes(n);
  while(t--)
  {
    int r;
    cin >> r;
    while(r>1)
    {
      cout << numbers[r] << " ";
      r/=numbers[r];
    }
    cout << endl;
  }
}

void genPrimes(int n)
{
  numbers[1]=1;
  for(int i=0;i<n;i++) numbers[i]=i;
  for(int i=2;i<sqrt(n);i++)
  {
    if(numbers[i]==i)
    {
      for(int j=2;j*i<n;j++)
      {
        numbers[j*i]=i;
      }
    }
  }
}
