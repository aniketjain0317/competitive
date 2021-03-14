#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &A)
{
    for(int i = 0; i < (int)A.size(); ++i)
    {
        int min_index = min_element(A.begin()+i,A.end())-A.begin();
        if(i != min_index) swap(A[i], A[min_index]);
    }
}

int main() {
    vector<int> A = {5, 2, 6, 7, 2, 1, 0, 3};
    selectionSort(A);
    for(int num : A)
        cout << num << ' ';
    return 0;
}
