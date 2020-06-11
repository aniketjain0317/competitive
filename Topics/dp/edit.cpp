// Problem #3 - GFG - DP Interview Questions
//Solved (same concept as #2)

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

string a;string b;

bool ch(int m,int n)
{
  return (a[m]==b[n]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test(t)
  {
    int l1,l2; cin >> l1 >> l2;
    cin >> a >> b;
    int arr[l1][l2];
    fr(i,0,l1)
    {
      fr(j,0,l2)
      {
        if(ch(i,j))
        {
          if(i==0)
          {
            if(j==0) arr[i][j]=0;
            else arr[i][j]=max(arr[i][j-1],j);
          }
          else if(j==0) arr[i][j]=max(arr[i-1][j],i);
          else arr[i][j]=arr[i-1][j-1];
        }
        else
        {
          if(i==0)
          {
            if(j==0) arr[i][j]=1;
            else arr[i][j]=arr[i][j-1]+1;
          }
          else if(j==0) arr[i][j]=arr[i-1][j]+1;
          else arr[i][j]=min(min(arr[i-1][j-1],arr[i][j-1]),arr[i-1][j])+1;
        }
      }
    }
    cnl(arr[l1-1][l2-1]);
  }
}
