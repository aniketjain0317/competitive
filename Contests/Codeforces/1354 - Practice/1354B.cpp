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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 200000
// #define int int16_t;
// #define ll int64_t;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  test(t)
  {
    string s; cin >> s;
    int n = s.length();
    int prev[3]= {-1,-1,-1};
    int ans = N+1;
    fr(i,0,n)
    {
      char a = s[i];
      if(a=='1')
      {
        prev[0]=i;
        if(prev[1]==-1 || prev[2]==-1) continue;
        int x = i - min(prev[1],prev[2]);
        if(x<ans) ans = x;
      }
      else if(a=='2')
      {
        prev[1]=i;
        if(prev[0]==-1 || prev[2]==-1) continue;
        int x = i - min(prev[0],prev[2]);
        if(x<ans) ans = x;
      }
      else if(a=='3')
      {
        prev[2]=i;
        if(prev[1]==-1 || prev[0]==-1) continue;
        int x = i - min(prev[1],prev[0]);
        if(x<ans) ans = x;
      }
    }
    if(ans==N+1) ans=-1;
    cnl(ans+1);
  }
}
