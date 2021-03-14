#include <bits/stdc++.h>
using namespace std;


int fn(int a, int b);

int main()
{

    int arr[5] = {4,8,6,9,-1};
    string s = "jfsd jksbgasoif";
    sort(s.begin(),s.end());
    cout << s << endl;
    // 4,6,8
    sort(arr, arr+5);
    // [first,last) format
    // sort(arr,arr+3);
    // {4,6,8}

    vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(6);
    // {4,8,6}

    // vector<int>::iterator
    sort(v.begin(),v.end());
    // {4,6,8}
    reverse(v.begin(),v.end()-1);

    vector<int> v2(3,1);
    // {1,1,1,5}
    v2.push_back(5);
    vector<int> v3(v.begin(), v.end()-1);
    // {6,8,9}

  // can also be iterated upon just like arrays
  // for(int i=0;i<3;i++) cout << v3[i] << endl;

  for(auto it=v.begin(); it!=v.end(); it++)
  {
    // auto == vector<int>::iterator
    // use it!=v.end(), not < (though it can be done for vectors, may not be true for other stuff)
    // it++, --, (+= n) can all be done, it+n doesnt work tho (same as above)

    // cout << *it << endl;
  }

  // cout << *(v.end()-1) << endl;
  v2.pop_back(); // Does not return the last element
  // 1,1,1
  // cout << v.size() << endl;
  // v2.clear();
  // {}
  v2.resize(10,0);
  for(auto x: v2)
  {
    cout << x << endl;
  }
}

// 4,8,6
int fn(int a, int b) {return (abs(a-6)<abs(b-6));}
// return 1 => a comes first
// return 0 => b comes first
