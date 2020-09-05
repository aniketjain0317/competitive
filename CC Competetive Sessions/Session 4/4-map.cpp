#include <bits/stdc++.h>
using namespace std;

int main()
{
  // ordered using 3rd optional compare property
  // all operations O(log n) on average
  map<long long int,int,greater<int>> m1;
  m1[2]++; // =1;
  m1[1]=2;

  cout << m1[3] << endl;



  // for(auto pi: m1) cout << pi.first << " " << pi.second << endl;

  for(auto it=m1.begin(); it!=m1.end(); it++)
  {
    auto pi = *it;
    cout << pi.first << " " << pi.second << endl;
  }


  m1.erase(m1.find(3));
  if(m1.find(3)!=m1.end()) cout << "YES\n";
  if(m1.count(3)) cout << "HAAN\n";
  cout << m1.size() << endl;

  // All operations take O(1) time on average (implemented using hash table)
  unordered_map<int,int> m2;



}
