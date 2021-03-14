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
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  test(t)
  {
    int n,m; cin >> n >> m;
    int p[n], f[n], s[m]={};
    cinp(n,f);
    cinp(n,p);
    fr(i,0,n)
    {
      s[f[i]-1]+=p[i];
    }
    sort(s,s+m);
    fr(i,0,m) if(s[i]) {cnl(s[i]); break;}
  }

}
