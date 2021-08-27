// Problem
//

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


#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1000000007;
const ll INF = 1000000007;
const int N = 100005;

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    string s; cin >> s;
    sort(all(s));
    int n = s.size();
    map<char,int> mp;
    for(auto x: s) mp[x]++;
    vpi v(mp.begin(), mp.end());
    string ans(n,v[0].fs);
    int a  = v[0].sn, curr;

    // case where min f(t)==0 (one char is unique)
    // baaaacddefg...
    for(auto p: v) if(p.sn==1)
    {
      ans.clear();
      ans+=p.fs;
      for(auto c: s) if(c!=p.fs) ans+=c;
      goto end;
    }
    if(v.size()==1) ans = s; // case of only one char
    else if(n>=(2*a-2)) // case where (aa.a.a.a.) strategy works
    {
      curr = a;
      fr(i,0,n)
      {
        if(a && (i%2==1 || !i)) ans[i]=v[0].fs, a--;
        else ans[i]=s[curr++];
      }
    }
    else if(v.size()==2) frr(i,1,v[1].sn) ans[i]=v[1].fs; // abbbaaaaaaaa....
    else // abaaaaacbcdd...
    {
      ans[1]=v[1].fs, v[1].sn--;
      ans[a+1]=v[2].fs, v[2].sn--;
      curr=a+2;
      fr(i,1,v.size()) fr(j,0,v[i].sn) ans[curr++]=v[i].fs;
    }

    end:
    cnl(ans);
  }
}
first sort s. then:
1. s = "aacdd" // atleast 1 character occours only once
      ans = "caadd" // push that char to front.
2. s = "aaaaaaaaa" // only 1 char present
      ans = "aaaaaaaaa"
3. s = "aaaabbccdd" // no(first char)-2>=no(rest chars)
      ans = "aababacacdd" //aa.a.a.a...
4. s = "aaaaaaaabbb" // only 2 chars present
      ans = "abbbaaaaaaaa"
5. s = "aaaaaaaabbccdd" //rest of the cases
      ans = "abaaaaaaacbcdd"
