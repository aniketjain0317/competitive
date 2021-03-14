#include <bits/stdc++.h>
using namespace std;

void recursionSort(vector<int> &A, int l, int r)
{
  // Base Case:
  if(l>=r) return;
  // Divide:
  int m =(l+r)/2;
  recursionSort(A,l,m);
  recursionSort(A,m+1,r);

  // Merge: (O(r-l))
  vector<int> B;
  int i=l, j=m+1;
  while(i<=m && j<=r)
  {
    if(A[i]<=A[j]) B.push_back(A[i++]);
    else B.push_back(A[j++]);
  }

  while(i<=m) B.push_back(A[i++]);
  while(j<=r) B.push_back(A[j++]);

  for(int k=l; k<=r; k++) A[k]=B[k-l];
}

int main() {
    vector<int> A = {5, 2, 6, 7, 2, 1, 0, 3};

    recursionSort(A,0,A.size()-1);
    for(int num : A)
        cout << num << ' ';
    return 0;
}
