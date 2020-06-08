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
#define show1d(arr) for(auto x: arr) csp(x); cout<<endl;
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
    ll x,y,x3,y3; cin >> x3 >> y3;
    x=abs(x3); y = abs(y3);
    ll flag=0,flag1=0;
    ll k = floor(log2(abs(x+y)));
    if(x+y==0 || !((x+y)%2)) {cout << "CASE #" << tno << ": " << "IMPOSSIBLE"<< endl;continue;}
    int sg1=1, sg2=1;
    if(x==0) sg1=1;
    else if(x!=0) {sg1 = x3/x;}
    if(y==0) sg2=1;
    else if(y!=0) {sg2 = y3/y;}

    ll sg = (x+y) / abs(x+y);

    ll a=pow(2,k) - abs(x+y)/2 - 1;
    vi a2;
    while(a>0)
    {
      ll r = a%2;
      a2.pb(r);
      a=a/2;
    }
    ll arr[k+1]={};
    fr(i,0,k+1) arr[i]=1;
    fr(i,0,a2.size())
    {
      if(a2[i]) arr[i]=-1;
    }
    if(sg==-1) fr(i,0,k+1) arr[i]*=-1;
    ll base2[k+1]={};
    fr(i,0,pow(2,k+1))
    {
      ll x1=x, y1=y;
      ll flag2=0;
      ll a =i;
      ll j=0;
      while(a>0)
      {
        ll r = a%2;
        base2[j]=(r);
        a=a/2; j++;
      }
      fr(j,0,k+1)
      {
        ll z = arr[j]*pow(2,j);
        if(base2[j]) x1-=z;
        else y1-=z;
      }
      if(x1==0&&y1==0)
      {
        flag1=1;
        break;
      }
    }
    if(flag1)
    {
      cout << "CASE #" << tno << ": ";
      fr(i,0,k+1)
      {
        if(base2[i])
        {
          arr[i]*=sg1;
          if(arr[i]==1) cout << "E";
          else if(arr[i]==-1) cout << "W";
        }
        else if(!base2[i])
        {
          arr[i]*=sg2;
          if(arr[i]==1) cout << "N";
          else if(arr[i]==-1) cout << "S";
        }
      }
      cout << endl;
    }
  }
}
