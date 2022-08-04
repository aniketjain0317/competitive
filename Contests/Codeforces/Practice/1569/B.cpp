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
#define cp2(x) (__builtin_popcountll(x)==1)
#define lp2(x) (__builtin_ctzll(x))
#define tc(tno) cout << "Case #" << tno << ": "


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
// #define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1000000007;
const ll INF = 1LL<<62;
const int N = 100005;

// vector<int> fn(vector<string> words, int k)
// {
//   int n = words.size();
//   vector<vector<int>> trie(10000, vector<int>(26,0));
//   vector<int> ans(k,0);
//   int ls = 1;
//   for(auto &s: words)
//   {
//     int curr = 1;
//     csp(s);
//     for(auto &c: s)
//     {
//       if(!trie[curr][c-'a']) trie[curr][c-'a'] = ++ls;
//       curr = trie[curr][c-'a'];
//       cnt[curr]++;
//       csp(curr);
//     }
//     cout << endl;
//   }
//
//   queue<pair<int,int>> q; q.push({1,0});
//   while(!q.empty())
//   {
//     cnl(q.front());
//     int node = q.front().first, level = q.front().second; q.pop();
//     if(1<=level && level<=k) ans[level-1]++;
//     for(auto &child: trie[node]) if(child) q.push({child, level+1});
//   }
//   return ans;
// }
//
// int fn2(int sum, int n)
// {
//   vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
//   dp[0][0]=1;
//   for(int i = 1; i<=n; i++)
//     for(int r = 0; r<=sum; r++)
//       for(int d = 0; (r+d)<=sum; d++)
//         dp[i][(r+d)]+=dp[i-1][r];
//   int ans = 0;
//   for(int i = 1; i<=n; i++) ans+=dp[i][sum];
//   return ans;
// }

// void rec(string &curr, vector<int> &ccnt, vector<string> &ans)
// {
//   int ch = 0;
//   for(int i = 0; i<26; i++) if(ccnt[i]>=2)
//   {
//     ch++;
//     string nxt = curr+(char)(i+'a');
//     vector<int> cnt(ccnt); cnt[i]-=2;
//     rec(nxt, cnt,ans);
//   }
//   if(!ch)
//   {
//     int od = -1;
//     for(int i = 0; i<26; i++) if(ccnt[i]==1) od = i;
//     string rev(curr);
//     reverse(rev.begin(), rev.end());
//     if(od!=-1) curr+=(od+'a');
//     curr+=rev;
//     ans.push_back(curr);
//   }
// }
//
// vector<string> fn3(string s)
// {
//   vector<string> ans;
//   vector<int> cnt(26,0);
//   for(auto &c: s) cnt[c-'a']++;
//   int f = 0;
//   for(int i = 0; i<26; i++) if(cnt[i]%2) f++;
//   if(f>1) return {};
//   string curr = "";
//   rec(curr ,cnt, ans);
//   sort(ans.begin(), ans.end());
//   return ans;
// }

vector<int> fn4(vector<int> s, vector<int> d, vector<int> p)
{
  int n = s.size();
  vector<vector<int>> v;
  for(int i = 0; i<n; i++) v.push_back({s[i], -p[i], d[i] , i});
  sort(v.begin(), v.end());
  for(int i = 0; i<n; i++) swap(v[i][0], v[i][1]);
  int ct = 0, i = 0;
  priority_queue<vector<int>, vector<int>, greater<vector<int>>> pq;
  vector<int> ans;
  while(i<n || !pq.empty())
  {
    if(pq.empty()) pq.push(v[i]), ct = v[i++][1];
    auto curr = pq.top(); pq.pop();
    ans.push_back(curr[3]);
    int nxt = ct+curr[2];
    while(i<n && v[i][1]<=nxt) pq.push(v[i++]);
    ct = nxt;
  }
  return ans;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  // cout << fn({"abc","ab","abd","a"},3) << endl;
  // cout << fn2(5,2) << endl;
  // cout << fn({"apple" , "app", "apricot","stone"},8) << endl;
  // cout << fn3("ababb") << endl;
  cout << fn4({0,1,2,3}, {4,1,1,1}, {0,1,2,3}) << endl;
}
