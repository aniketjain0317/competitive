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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll ans=0;
  for(ll i=0;i<=pow(2,29);i++)
  {
    ll sum=0, j=i;
    int one=0, zero=0, flag=0;
    for(int k=0;k<30||j>0;k++)
    {
      int x=j%2;
      j/=2;
      if(x) {sum++;one++;}
      else {sum--;zero++;}

      if((sum<=0)||(one>18)||(zero>12)) {flag=1;break;}
    }
    if(!flag) {ans++;}
  }
  cnl(ans);
}
