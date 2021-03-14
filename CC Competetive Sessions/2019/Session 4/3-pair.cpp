#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x,y;
};

typedef pair<int,int> pii;

int main()
{
  pair<int,long long> p1(2,2);

  pair<int,long long> p2(1,5);

  cout << (p1>=p2) << endl;
  // all relational operators work. No other operators tho (except =)

  pii p3;
  p3 = make_pair(3,3);

  vector<pii> v(3,make_pair(5,2));
  v.push_back({3,3});
  for(auto p: v)
  {
    cout << p.fs << endl;
  }

}
