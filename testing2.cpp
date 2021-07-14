#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,X; cin >> N;
  vector<long long> A(N);
  for(int i =0; i<N; i++)
    cin >> A[i];
  cin >> X;

  long long LMAX = 1LL<<60;
  long long LMIN = -LMAX;

  long long mx[2]={LMIN,LMIN};
  mx[A[0]&1]=A[0];
  for(int i = 1; i<N; i++)
  {
    bool b = A[i]&1;
    long long curr = A[i] + max(mx[!b] - X, mx[b]);
    mx[b] = max(mx[b], curr);
    if(i==N-1) cout << curr << endl;
  }
}
