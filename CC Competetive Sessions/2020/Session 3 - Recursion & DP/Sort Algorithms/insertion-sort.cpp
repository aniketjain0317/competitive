#include <bits/stdc++.h>
using namespace std;

void recursionSort(vector<int> &A, int n)
{
  // Base Case:
  if(n<=1) return;
  // Divide:
  recursionSort(A,n-1);

  // Merge:
  int last = A[n-1];
  int i=n-2;
  while(i>=0 && A[i]>last)
  {
    swap(A[i],A[i+1]);
    i--;
  }
}

int main() {
    vector<int> A = {5, 2, 6, 7, 2, 1, 0, 3};

    recursionSort(A, A.size());
    for(int num : A)
        cout << num << ' ';
    return 0;
}
