#include <bits/stdc++.h>
using namespace std;

bool fn(int a, int b)
{
  if(!(a&1) && b%2) return 1;
  else if(b%2==0 && a%2) return 0;
  else if(a%2==0 && b%2==0) return a<b;
  else return a>b;
}
// return 1: a,b
// return 0: b,a


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int arr[3]={6,4,5};
  deque<int> dq;
  dq.push_back(4);
  dq.push_front(6);
}
// [first,last)
// comparator
