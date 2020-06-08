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
    ll n,k; cin >> n >> k;
    vi arr(n+1);
    frr(i,0,n) arr[i]=i*(i+1)/2;
    ll x = lb(arr.begin(),arr.end(),k) - arr.begin();
    ll y = n-x-1;
    ll z = n - k + arr[x-1];
    fr(i,0,n)
    {
      if(i==y || i==z) cout << 'b';
      else cout << 'a';
    }
    cout << endl;
  }
}
