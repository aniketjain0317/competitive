// Problem
//AC

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
  test(t)
  {
    int n; cin >> n;
    int plays[n];
    int clears[n];
    int flag=0;
    fr(i,0,n) cin >> plays[i] >> clears[i];
    fr(i,0,n)
    {
      int p;int c;
      if(!i) {p=plays[0];c = clears[0];}
      else
      {
        p = plays[i]-plays[i-1];
        c = clears[i]-clears[i-1];
      }
      if(p<0) flag=1;
      else if(c<0) flag=1;
      else if(c>p) flag=1;

      if(flag) {break;}
    }
    if(flag) cnl("NO");
    else cnl("YES");
  }
}
