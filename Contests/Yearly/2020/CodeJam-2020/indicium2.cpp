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
  test(t)
  {
    int n,k; cin >> n >> k;
    int arr[n][n]={};
    cout << "Case #"<< tno << ": ";

    int f=0, q = k/n, r = k%n;
    if(n==3&&(k!=3&&k!=6&&k!=9)) f=1;
    else if(q<1 || q>n) f=1;
    else if (q==1 && r==1) f=1;
    else if(q==n && r!=0) f=1;
    else if(q==n-1 && (r==n-1)) f=1;
    if(f==1) {cnl("IMPOSSIBLE");continue;}

    int trace[n]={};
    fr(i,0,n) trace[i]=q;
    if(r==1) {trace[0]+=1;trace[1]+=1;trace[2]-=1;;}
    else if(r==n-1) {fr(i,0,n-1) trace[i]+=1;trace[0]-=1;trace[1]+=1;}
    else {fr(i,0,r) trace[i]+=1;}


    if(!r) fr(i,0,n) fr(j,0,n)
    {
      int x = (q + j - i);
      if(x<1) x+=n;
      if(x>n) x-=n;
      arr[i][j]=x;
    }
    else if(r>1&&r<n) fr(i,0,n) fr(j,0,n)
    {
      int x = (q + j - i);
      if(i<r) {if(j==i) x+=1;if(j==i+1) x-=1;}
      // if(i==r-1)
      // {
      //   if(j==0) x=q;
      //   else if(j<r-1 || j==r) x-=1;
      // }
      // if(i==n-1)
      // {
      //   if(j);
      // }

      if(x<1) x+=n;
      if(x>n) x-=n;
      arr[i][j]=x;
    }

    cnl("POSSIBLE");
    fr(i,0,n)
    {
      fr(j,0,n)
      {
        csp(arr[i][j]);
      }
      cout << endl;
    }
  }
}
