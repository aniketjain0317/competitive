#include <bits/stdc++.h>
using  namespace std;


// queue, stack, priority_queue
// stack - LIFO: Last in first out
// queue - FIFO: first in first out


int main()
{
  stack <int, deque<int>> s1;
  s1.push(1);
  s1.push(3);
  s1.push(2);
  s1.pop();
  // cout << s1.top() << endl;
  // s1.size(), s1.empty()

  queue<int> q1;
  q1.push(1);
  q1.push(3);
  q1.push(2);
  q1.pop();
  q1.pop();
  if(q1.size()>1) q1.pop();
  // cout << q1.front() << endl;
  // q1.size(), q1.empty(), q1.back()

  //
  priority_queue<int, deque<int>, greater<int>> pq;
  pq.push(1);
  pq.push(3);
  pq.push(2);
  cout << pq.top() << endl;
  // pq.size(), pq.empty()
}
