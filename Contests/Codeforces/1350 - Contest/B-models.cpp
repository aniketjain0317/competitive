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
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a;i<=b;i++)
#define test(t) ll t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000

typedef long long int ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  test(t)
  {
    ainp(n,arr);
    ll dp1[n]={};
    ll dp2[n]={};
    dp1[0]=1; dp2[0]=1;
    fr(i,1,n)
    {
      fr(j,0,sqrt(i))
      {
        if((i+1)%(j+1)==0)
        {
          ll p = 1;
          ll m = (i+1)/(j+1) - 1;
          if(arr[j]<arr[i]) p = dp2[j] +1;
          if(arr[m] < arr[i]) p = max(p,dp2[m]+1);
          if(p>dp2[i]) dp2[i]=p;
        }
      }
      if(dp2[i]>dp1[i-1]) dp1[i]=dp2[i];
      else dp1[i] = dp1[i-1];
    }
    cnl(dp1[n-1]);
  }
}
