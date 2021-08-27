// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    if(n==1) {cout << 'x' << endl; continue;}
    int k = n/2;
    string s;
    for(int i = 0; i<k; i++) s+='x';
    s+='y';
    for(int i = 0; i<(k-1); i++) s+='x';
    if(n&1) s+='z';
    cout << s << endl;
  }
}
