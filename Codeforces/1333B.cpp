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
    ainp(n,a);
    ll b[n];
    cinp(n,b);
    int ch1=n,ch2=n+1;
    int flag=0;
    fr(i,0,n)
    {
      if(ch1==n && a[i]==1) ch1=i;
      else if(ch2==n+1 && a[i]==-1) ch2=i;
    }
    if(ch1==n && ch2==n+1)
    {
      fr(i,0,n) if(a[i]!=b[i]) {flag=1; break;}
      if(flag) {cnl("NO"); continue;}
      else {cnl("YES"); continue;}
    }
    else if(ch2==n+1)
    {
      frr(i,0,ch1) if(a[i]!=b[i]) {flag=1; break;}
      if(flag) {cnl("NO"); continue;}

      frr(i,ch1+1,n-1) if(a[i]>b[i]) {flag=1;break;}
      if(flag) {cnl("NO"); continue;}
      else {cnl("YES"); continue;}
    }
    else if(ch1==n)
    {
      frr(i,0,ch2) if(a[i]!=b[i]) {flag=1; break;}
      if(flag) {cnl("NO"); continue;}

      frr(i,ch2+1,n-1) if(a[i]<b[i]) {flag=1;break;}
      if(flag) {cnl("NO"); continue;}
      else {cnl("YES"); continue;}
    }


    if(ch1<ch2)
    {
      frr(i,0,ch1) if(a[i]!=b[i]) {flag=1; break;}
      if(flag) {cnl("NO"); continue;}
      frr(i,ch1+1,ch2) if(a[i]>b[i]) {flag=1;break;}
      if(flag) {cnl("NO"); continue;}
    }
    else if(ch2<ch1)
    {
      frr(i,0,ch2) if(a[i]!=b[i]) {flag=1; break;}
      if(flag) {cnl("NO"); continue;}
      frr(i,ch2+1,ch1) if(a[i]<b[i]) {flag=1;break;}
      if(flag) {cnl("NO"); continue;}
    }
    cnl("YES");
  }
}
