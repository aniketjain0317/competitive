//Problem 1294A - Codeforces (Contest / 9000)
// Solved (Problematic Test Case)

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    long a,b,c,n;
    cin >> a >> b >> c >> n;
    int flag=0;
    int x = (a+b+c+n)%3;
    if(x) {cout << "NO\n"; continue;}
    int d = (a+b+c+n)/3;

    if(d-a>n||d<a) {cout << "NO\n"; continue;}
    if(d-b>n||d<b) {cout << "NO\n"; continue;}
    if(d-c>n||d<c) {cout << "NO\n"; continue;}
    cout << "YES\n";
  }
}
