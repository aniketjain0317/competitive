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
  string n="a";
  while(n!="0")
  {
    cin >> n;
    int len = n.size();
    int dp[len]={};
    dp[0]=1;
    char prev=n[0];
    fr(i,2,len)
    {
      char x = n[i];
      int flag=0;
      if(prev=='1') flag =1;
      else if(prev=='2' && (x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6')) flag=1;
      prev=x;
      if(x=='0') dp[i]=dp[i-2];
      else if(flag) dp[i]=dp[i-1]+dp[i-2];
      else dp[i]=dp[i-1];
      cnl(dp[i]);
    }
    cnl(dp[len-1]);
  }
}
