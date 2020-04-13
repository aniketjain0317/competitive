// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  test(t)
  {
    int n; cin >> n;
    int arr[n][n];
    fr(i,0,n) fr(j,0,n) cin >> arr[i][j];
    // Trace
    int trace = 0;
    fr(i,0,n) trace += arr[i][i];
    // Row
    int row = 0;
    fr(i,0,n)
    {
      int check[n+1]={};
      int flag=0;
      fr(j,0,n)
      {
        int x = arr[i][j];
        if(!check[x]) check[x]++;
        else {flag=1;break;}
      }
      if(flag) row++;
    }
    // Column
    int col = 0;
    fr(j,0,n)
    {
      int check[n+1]={};
      int flag=0;
      fr(i,0,n)
      {
        int x = arr[i][j];
        if(!check[x]) check[x]++;
        else {flag=1;break;}
      }
      if(flag) col++;
    }

    cout << "Case #"<< tno << ": " << trace << " " << row << " " << col << endl;
  }
}
