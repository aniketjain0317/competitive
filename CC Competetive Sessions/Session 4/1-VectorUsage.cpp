#include <bits/stdc++.h>
using namespace std;


int fn(int a, int b);

int main()
{

  int arr[3] = {4,8,6};

  // [first,last) format
  sort(arr,arr+3);
  // {4,6,8}

  vector<int> v;
  v.push_back(4);
  v.push_back(8);
  v.push_back(6);
  // {4,8,6}

  // vector<int>::iterator
  sort(v.begin(),v.end(),fn);
  reverse(v.begin(),v.end());
  // for(auto x: v) cout << x << endl;


  vector<int> v2(3,1);
  // {1,1,1}

  vector<int> v3 (arr,arr+3);
  // {4,6,8}

  // can also be iterated upon just like arrays
  // for(int i=0;i<3;i++) cout << v3[i] << endl;

  for(auto it=v.begin(); it!=v.end(); it++)
  {
    // auto == vector<int>::iterator
    // use it!=v.end(), not < (though it can be done for vectors, may not be true for other stuff)
    // it++, --, (+= n) can all be done, it+n doesnt work tho (same as above)

    // cout << *it << endl;
  }

  // cout << v.back() << endl;
  v.pop_back(); // Does not return the last element

  v.clear();
  if(v.empty()) v.resize(10,0);
  cout << v.size() << endl;
}

// 4,8,6
int fn(int a, int b) {return (abs(a-6)<abs(b-6));}
// return 1 => a comes first
// return 0 => b comes first
