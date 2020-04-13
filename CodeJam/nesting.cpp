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
    string s;
    cin >> s;
    int n = s.length();
    string ans = "";
    int p =0;
    fr(i,0,n)
    {
      char c = s[i];
      int x = c - 48;
      if(x>p) fr(i,0,x-p) ans+="(";
      else if (x<p) fr(i,0,p-x) ans+=")";
      p=x;
      ans+=c;
    }
    fr(i,0,p) ans+=")";

    cout << "Case #"<< tno << ": " << ans<< endl;

  }
}
