#include <bits/stdc++.h>
using namespace std;
map <int,int> factorise(map<int,int> factors, int num)
{
  int p2=0;
  while(!(num%2)) {num>>=1; p2++;}
  factors[2]+=p2;
  for (int i=3;i<=sqrt(num);i+=2)
  {
    int power=0;
    if (!num%i) {num/=i; power++;}
    if (power) factors[i]+=power;
  }
  if (num>2) factors[num]+=1;
  return factors;
}



int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    while(n--) cin >> arr[n];
    map <int,int> factors;
    for(int num:arr)
    {
      factors=factorise(factors,num);
    }
    int ans=1;
    for (auto p:factors) ans*=(p.second+1);
    cout << ans << endl;
  }
}
