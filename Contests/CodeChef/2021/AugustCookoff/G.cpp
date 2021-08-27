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
const ll INF = 1LL<<62;
const int N = 100005;

struct STMin{
    vector<int> t;
    void init(int n,int x = INF){
        t.resize(4*n,x);
    }
    void build(vector<int>&a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
	          t[v] = min(t[v*2], t[v*2+1]);
        }
    }
	   void print(){
		for(int i = 0;i<t.size();i++){
			cout<<t[i]<<" ";
		}
		cout<<endl;
	}

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INF;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};
struct STMax{
    vector<int> t;
    void init(int n,int x = -INF){
        t.resize(4*n,x);
    }
    void build(vector<int>&a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
	          t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -INF;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};


intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    ainp(n,arr);
    vi pref(n+1,0);
    fr(i,0,n) pref[i+1] = pref[i]+arr[i];
    STMin mn; mn.init(n+1); mn.build(pref,1,0,n);
    STMax mx; mx.init(n+1); mx.build(pref,1,0,n);


    vvi nge(n, vi(2,-1));
    fr(i,0,n) nge[i][0]=n;
    vvi ne(n, vi(2,-1));
    fr(i,0,n) ne[i][0]=n;
    // NGE (0)
    stack<int> s; s.push(0);
    fr(i,1,n)
    {
      if(s.empty())
      {
        s.push(i);
        continue;
      }
      while(!s.empty() && arr[s.top()] < arr[i])
      {
        nge[s.top()][0] = i;
        s.pop();
      }
      s.push(i);
    }
    while(!s.empty()) s.pop();
    // PGE (1)
    s.push(n-1);
    frrb(i,n-2,0)
    {
      if(s.empty())
      {
        s.push(i);
        continue;
      }
      while(!s.empty() && arr[s.top()] < arr[i])
      {
        nge[s.top()][1] = i;
        s.pop();
      }
      s.push(i);
    }

    // {
    //   map<int,int> mp;
    //   fr(i,0,n)
    //   {
    //     if(mp.count(arr[i])) ne[i][0] = mp[arr[i]];
    //     mp[arr[i]] = i;
    //   }
    //   mp.clear();
    //   frrb(i,n-1,0)
    //   {
    //     if(mp.count(arr[i])) ne[i][1] = mp[arr[i]];
    //     mp[arr[i]] = i;
    //   }
    // }

    int ans = 0;
    // i = 2nd max
    fr(i,0,n)
    {
      // j<i
      if(max(ne[i][1], nge[i][1])!=-1)
      {
        int j = max(ne[i][1], nge[i][1]);
        int lc1 = nge[j][1], lc2 = j-1;
        int rc2 = nge[i][0]-1, rc1 = i;
        // l:[lc1+1, lc2+1], r:[rc1+1,rc2+1];
        csp("CH"); csp(i); cnl(j);
        csp(lc1); csp(lc2); csp(rc1); cnl(rc2);
        if(lc1<=lc2 && rc1<=rc2)
        {
          // if(chmax(ans, pr-pl-arr[i]-arr[j])) csp("CHECK"),csp(i), csp(j), cnl(ans);
          int pl = mn.query(1,0,n,lc1+1, lc2+1);
          int pr = mx.query(1,0,n,rc1+1, rc2+1);
          csp(pl); cnl(pr);
          mxs(ans, pr-pl-arr[i]-arr[j]);
        }
      }
      // i<j
      // rightmost index less than i, but arr[]>arr[i]
      if(min(nge[i][0], ne[i][0]) == n)
      {
        int j = min(nge[i][0], ne[i][0]);
        int lc1 = nge[i][1], lc2 = i-1;
        int rc2 = nge[j][0]-1, rc1 = j;
        // l:[lc1+1, lc2+1], r:[rc1+1,rc2+1];
        csp("CH"); csp(i); cnl(j);
        csp(lc1); csp(lc2); csp(rc1); cnl(rc2);
        if(lc1<=lc2 && rc1<=rc2)
        {
          int pl = mn.query(1,0,n,lc1+1, lc2+1);
          int pr = mx.query(1,0,n,rc1+1, rc2+1);
          csp(pl); cnl(pr);
          // if(chmax(ans, pr-pl-arr[i]-arr[j])) csp("CHECK"),csp(i), csp(j), cnl(ans);
          mxs(ans, pr-pl-arr[i]-arr[j]);
        }
      }
    }
    csp("AAAAAAAA");
    cnl(ans);
  }
}
