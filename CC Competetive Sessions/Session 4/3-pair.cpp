#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x,y;
};

int main()
{
  pair<int,int> p1;
  p1.first = 1;
  p1.second =2;

  pair<int,int> p2(1,3);
  
  cout << (p1>=p2) << endl;
  // all relational operators work. No other operators tho (except =)

  pair <int,int> p3;
  p3 = make_pair(3,3);


}
