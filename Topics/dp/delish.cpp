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


ll bestSum(ll arr[]);
ll worstSum(ll arr[]);
int main()
{
  test(t)
  {
    int n; cin >> n;
    ll arr[n]; cinp(n,arr);
    ll best=0;
    ll current1=0;
    ll worst=0;
    ll current2=0;
    ll ans=0;
    for(ll x: arr)
    {
      ans=best-worst;
      current1+=x;
      if(current1<0) current=0;
      if(best<current1) best=current1;
    }
  }
}

ll bestSum(ll arr[])
{

  return best;
}
