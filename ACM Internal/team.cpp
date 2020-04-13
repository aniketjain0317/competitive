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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m; cin >> n >> m;
  int x=m+n;
  if(m>2*(n+1) || m<n-1) {cnl(-1);return 0;}
  if(m==n-1)
  {
    fr(i,0,x)
    {
      if(!(i%2)) cout << 0;
      else cout <<  1;
    }
    return 0;
  }

  int i=0,last=1;
  while(m!=n)
  {
    if(i%3==2) {cout << 0; n--;last=0;}
    else {cout << 1; m--;last=1;}


    i++;
  }
  for(;i<x;i++)
  {

    if(last==0) {cout << 1;last=1;}
    else {cout << 0; last=0; }
  }
  cout << endl;
}
