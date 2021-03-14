#include <bits/stdc++.h>
using namespace std;

// A[l,r]
void recursionSort(vector<int> &A, int l, int r)
{
  // BASE CASE:
  if(r-l<=0) return;
  // DIVIDE:
  int m = (l+r)/2;
  recursionSort(A, l, m);
  recursionSort(A, m+1,r);
  // MERGE:
  vector<int> B;
  int i=l ,j=m+1;
  while(i<=m && j<=r)
  {
    if(A[i]<=A[j]) B.push_back(A[i++]);
    else B.push_back(A[j++]);
  }
  while(i<=m) B.push_back(A[i++]);
  while(j<=r) B.push_back(A[j++]);

  for(int k=l; k<=r; k++)
  {
    A[k]=B[k-l];
  }
}


int main() {
    vector<int> A = {5, 2, 6, 7, 2, 1, 0 , 3};
    recursionSort(A, 0, A.size()-1);
    for(int num : A)
        cout << num << ' ';
    return 0;
}

// Time:
// O(Merge) *O(no of times it is called)
// // 0 1 2 2 3 5 6 7
// 3: n-2
// i: n-3
// i, i+1
