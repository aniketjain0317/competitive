#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  int arr[n]={};
  for(int i=0; i<n;i++) cin >> arr[i];
  deque<int> q; deque<int> s;

  for(auto x: arr)
  {
    if(q.empty() and s.empty()) q.push_back(x);
    else if(x>=q.back()) q.push_back(x);
    else if(s.empty() || x<=s.front()) s.push_front(x);
    else
    {
      while(!s.empty())
      {
        if(s.front()<=q.front()) {q.push_back(s.front()); s.pop_front();}
        else {q.push_back(q.front()); q.pop_front();}
      }
      while(q.front()<x) {q.push_back(q.front()); q.pop_front();}
      s.push_front(q.front()); q.pop_front();
      s.push_front(x);
      while(q.front()>q.back()) {q.push_back(q.front()); q.pop_front();}
    }

    if(!q.empty())
    {
      for(auto x: q) cout << x << " ";
      cout << endl;
    }
    if(!s.empty())
    {
      for(auto x: s) cout << x << " ";
      cout <<endl;
    }
  }
}
