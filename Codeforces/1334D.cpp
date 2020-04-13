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
  test(t)
  {
    ll n,l,r; cin >> n >> l >> r;
    ll total = n*(n-1) +1;
    vector <ll> arr(n+1,0);
    for(ll i=1;i<=n;i++) {arr[i]=2*i*n - (i*(i+1));}


    for(ll i = l;i<=r;i++)
    {
      ll x =0;
      ll id=lb(arr.begin(),arr.end(),i)-arr.begin()-1;
      ll z = i;
      z-=arr[id++];
      if(i==total) x=1;
      else if(z%2) x=id;
      else x=(z/2)+id;
      csp(x);
    }
    cout << endl;
  }
}

/*
3
2 1 3
3 3 6
99995 9998900030 9998900031

1 2 1 3 1 4
2 3 2 4
3 4
1
*/
