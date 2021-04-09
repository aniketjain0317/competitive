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
  string s1; string s2;
  cin >> s1 >> s2;
  int size1 = s1.size(), size2 = s2.size();
  int size = min(size1,size2);
  int dp[size1][size2]={};
  fr(i,0,size+1)
  {
    if(s1[i]==s2[i])
    {
      if(i==0) dp[0]=1;
      else dp[i]=dp[i-1]+1;
    }
    else dp[i]=dp[i-1];
  }
  cnl(dp[size-1]);
}
