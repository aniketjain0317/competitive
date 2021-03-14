// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define cnl(x) cout <<x<< endl;
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define test(t) int t; cin << t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  ainp(n,arr);
  sort(arr,arr+n);
  ll a1=0, a2=0, ans=0;
  fr(i,0,n/2+n%2)
  {
    a1+=arr[n-i-1];
    if(n%2 && i==(n/2)) break;
    a2+=arr[i];
  }
  ans=a1*a1+a2*a2;
  cnl(ans);
}
