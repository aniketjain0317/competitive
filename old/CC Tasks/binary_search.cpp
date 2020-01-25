#include <bits/stdc++.h>
using namespace std;
int ans(int n)
{
    int arr[n/2];
    for (int i=0;i<n/2;i++)
    {
        arr[i]=i;
    }
    int high=n/2-1,low=0;
    while(high>=low)
    {
        int mid=(high+low)/2;
        int ch=mid*(mid+1)/2;
        if(ch>n) high=mid-1;
        else if (ch<n) low=mid;
        else {return mid;}
    }
    return low;
}
int main()
{
    cout << ans(4);
}
