#include <bits/stdc++.h>
using namespace std;

int main()
{
  // ordered using 3rd optional compare property
  // all operations O(log n) on average

  map<long long,int, greater<int>> mp;
  mp[3];
  mp[1]=2;
  mp[10]++; // =1;
  cout << mp.size() << endl;



  for(auto pi: mp) cout << pi.first << " " << pi.second << endl;

  // for(auto it=mp.begin(); it!=mp.end(); it++)
  // {
  //   auto pi = *it;
  //   cout << pi.first << " " << pi.second << endl;
  // }

  mp.erase(mp.find(3));
  if(mp.find(7)!=mp.end()) cout << "YES\n";
  cout << mp.size() << endl;

  // All operations take O(1) time on average (implemented using hash table)
  unordered_map<int,int> m2;



}
