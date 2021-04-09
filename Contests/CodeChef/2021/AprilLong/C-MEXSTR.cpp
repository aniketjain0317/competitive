// Problem
//

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923a
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


#define pb push_back
#define mp make_pair
#define lb lower_bound
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
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
// #define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

string solve(string s)
{
  // cnl(s);
  int n = s.size();
  string ans;
  int i=0;
  char curr='.';
  set<char> st;
  int cnt[2]={}, prev=-10;
  while(i<n)
  {
    curr = s[i];
    st.insert(curr);
    if((prev==-10 && curr=='1') || st.size()==2)
    {
      if(prev==i-2 && curr=='1')
      {
        cnt[0]=1; cnt[1]=1;
        while(++i<n && s[i]!=s[i-1]) cnt[s[i]-'0']++;
        char x = s[i-2];
        if(i==n) x = s[i-1];
        fr(j,0,cnt[x-'0']) ans+=x;
        // csp("AAA"); csp(i); cnl(ans);
        st.clear();
        prev=i-2;
        continue;
      }
      prev=i;
      ans+=curr;
      st.clear();
    }
    // csp(i); cnl(ans);
    i++;
  }
  if(!st.empty()) for(auto c: st) ans+=c;
  return ans;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    string s;
    cin >> s;
    string s1=s+'0', s2 = s+'1';
    string a1 = solve(s1);
    string a2 = solve(s2);
    int no=0; for(auto c: s) no+=(c=='1');
    if(no==s.size()) cnl("0");
    else if(no==0) cnl("1");
    else cnl(min(a1,a2));
  }
}
