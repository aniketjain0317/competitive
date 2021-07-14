// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
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
#define intt int32_t
#define int long long

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> bool chmin(T& a, U b){if (a > b) {a = b; return true;} return false;}
template<typename T, typename U> bool chmax(T& a, U b){if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const ll INF = 1000000007;
const int N = 100005;

string ch = "haha";
int countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;

        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
        {
           res++;
           j = 0;
        }
    }
    return res;
}

vi init(string s)
{
  vi v(4,0);
  int sz = s.size();
  v[3] = sz;
  v[0] = countFreq(ch, s);
  if(sz>=1 && s[0]=='a') v[1]=1;
  if(sz>=2 && s[0]=='h' && s[1]=='a') v[1]=2;
  if(sz>=3 && s[0]=='a' && s[1]=='h' && s[2]=='a') v[1]=3;

  if(sz>=1 && s[sz-1]=='h') v[2]=3;
  if(sz>=2 && s[sz-1]=='a' && s[sz-2]=='h') v[2]=2;
  if(sz>=3 && s[sz-1]=='h' && s[sz-2]=='a' && s[sz-3]=='h') v[2]=1;
  return v;
}

// #define endl '\n'
intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n; cin >> n;
    map<string, int> mp;
    map<string, string> b;
    map<string, string> e;
    map<string, int> sizes;
    fr(i,0,n)
    {
      string s, var;
      cin >> s; var = s;
      cin >> s;
      if(s==":=")
      {
        cin >> s;
        int sz = s.size();
        mp[var] = countFreq(ch, s);
        b[var] = ""; e[var] = "";
        fr(i,0,3) if(sz>i) b[var]+= s[i];
        fr(i,0,3) if(sz>i) e[var]+= s[n-i];
      }
      else
      {
        string var2, var3;
        cin >> var2; cin >> s; cin >> var3;
        if(v[3]<10)
        {
          smol[var] = smol[var2] + smol[var3];
          v = init(smol[var]);
        }
        else
        {
          int cond = (mp[var2][2]==mp[var3][1] && mp[var2][2]);
          v[0] = mp[var2][0] + mp[var3][0] + cond;
          v[1] = mp[var2][1];
          v[2] = mp[var3][2];
        }
      }
      mp[var] = v;
      if(i==n-1)
        cnl(v[0]);
    }
  }
}
// item
// val: haha
// begin: 0=-,1=a,2=ha,3=aha
// end: 0=-, 1=hah,2=ha,3=h
