#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define fs first
#define sn second
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())


const int N = 1005;
int main()
{
  test(t)
  {
    int n; cin >> n;
    string s; cin >> s;
    int cnt[2][26]={};
    int cum[2][26]={};
    for(int i = 0; i<n; i++)
    {
      if((i+1)<=(n/2)) cnt[0][s[i]-'a']++;
      else cnt[1][s[i]-'a']++;
    }
    cum[0][0]=cnt[0][0];
    cum[1][0]=cnt[1][0];
    for(int i = 1; i<26; i++)
    {
      cum[1][i]=cum[1][i-1]+cnt[1][i];
      cum[0][i]=cum[0][i-1]+cnt[0][i];
    }
    // s[i] < s[j]
    int ans = INT_MAX;
    for(int c = 0; c<25; c++)
    {
      // [0...c] sirf first half me h
      // [c+1...25] sirf second half me h
      // second half me [0...c]
    }
  }
}
