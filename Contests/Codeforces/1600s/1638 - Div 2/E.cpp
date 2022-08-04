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
#define dsp(x) cout << #x << ": " << x << ", "
#define dnl(x) cout << #x << ": " << x << endl


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
template<typename T>             ostream& operator<<(ostream& os,  set<T>  v){os<<"{"; for (auto& i : v) os << i << ','; os<<"}"; return os;}

template<typename T, typename U> ostream& operator<<(ostream& os,  map<T, U>  v){for (auto& i : v) os << i.fs << ':' << i.sn << ", "; return os;}

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

struct item
{
  int color;
  int value;
  friend ostream& operator<<(ostream& os, const item& x) {os <<x.color << "," << x.value; return os;}
};
class SegTree
{
public:
  int n, m, h;
  vector<item> tree;
  vector<vector<int>> len; // [left,right)
  vector<bool> marked;
  map<int,int> global;
  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  item single(int v) // used only at initialization & reset
  {return {1,v};}

  SegTree(int sz)
  {
    n = 1, h = 1;
    while(n<sz) h++, n<<=1; m=n<<1;

    tree.resize(m, single(NEUTRAL));
    for(int i = 0; i<sz; i++) tree[n+i] = single(NEUTRAL);
    // for(int i = n-1; i; i--)  tree[i]   = merge(tree[2*i], tree[2*i+1]);

    len.resize(m, {0,n});
    for(int i = n; i<m; i++)   len[i][0] = i-n,         len[i][1] = i-n+1;
    for(int i = n-1; i>0; i--) len[i][0] = len[2*i][0], len[i][1] = len[2*i+1][1];
  }

  int query(int i, int x = 1)
  {
    int lx = len[x][0], rx = len[x][1];
    if((rx-lx)==1)      return tree[x].value;
    if(i < len[2*x][1]) return tree[x].value+query(i, 2*x);
    else                return tree[x].value+query(i, 2*x+1);
  }


  void addToColor(int c, int v, int x = 1)
  {
    global[c]+=v;
  }

  // updates all ancestors of [l,r) with the correct color.
  void setColor(int l, int r, int c, int x = 1)
  {
    int lx = len[x][0], rx = len[x][1];
    if(r<=lx || rx<=l) return;
    if(l<=lx && rx<=r) {tree[x].color = c; return;}
    setColor(l, r, c, 2*x);
    setColor(l, r, c, 2*x+1);
    if(tree[2*x].color == tree[2*x+1].color) tree[x].color = tree[2*x].color;
    else tree[x].color = -1;
  }

  void printTree()
  {
    cout << "TREEEEEEEEE: ";
    for(int i = 1; i<m; i++)
    {
      if(__builtin_popcountll(i)==1) cout << endl;
      cout << tree[i] << " ";
    }
    cout << endl;
  }
};


void solve()
{
  int n,q; cin >> n >> q;
  // int B = (int) sqrt (n + .0) + 1;
  // int m = n%B + 1;
  //
  // map<int, map<int,int>> update;
  // vector<map<int, int>> block_color(m+1), block_update(m+1);
  // vector<map<int, int>> value(n+1), color(n+1);
  // frr(i,0,n)
  // {
  //   value[i][-1] = 0;
  //   color[i][-1] = 1;
  // }
  // dsp(B), dnl(m);
  SegTree st(n);
  // auto getColorVal = [&](int c, int t1, int t2)
  // {
  //   if(update[c].empty()) return 0LL;
  //   auto it1 = update[c].lower_bound(t1);
  //   auto it2 = --update[c].upper_bound(t2);
  //   if(it1==update[c].end() || it2==update[c].end()) return 0LL;
  //   if(it1==update[c].begin()) return it2->sn;
  //   // if(show) dsp(c), dsp(it2->sn), dsp(it1->sn), dnl(update[c]);
  //   --it1;
  //   return it2->sn - it1->sn;
  // };
  // auto getBlockVal = [&](int j, int t1, int t2)
  // {
  //   if(block_update[j].empty()) return 0LL;
  //   auto it1 = block_update[j].lower_bound(t1);
  //   auto it2 = --block_update[j].lower_bound(t2);
  //   if(it1==block_update[j].end() || it2==block_update[j].end()) return 0LL;
  //   if(it1==block_update[j].begin()) return it2->sn;
  //   --it1;
  //   return it2->sn - it1->sn;
  // };
  //
  // auto getCurrentValue = [&](int i, int t)
  // {
  //   cnl(i);
  //   int show = 0;
  //   // if(t==5) show = 1;
  //   if(show) csp("getCurrentValue: ");
  //   int b = i/B;
  //   if(show) dsp(value[i]);
  //   int lsi = t, x = value[i].rbegin()->sn;
  //   if(show) dsp(i), dsp(t), dsp(x);
  //   auto it = color[i].rbegin();
  //   if(it==color[i].rend()) return 0LL;
  //   auto it1 = block_color[b].lb(it->fs);
  //   auto it2 = block_color[b].rbegin();
  //   if(it1!=block_color[b].end())
  //   {
  //     lsi = it1->fs;
  //     x += getBlockVal(b, it1->fs, it2->fs);
  //   }
  //   if(show) dsp(lsi);
  //   x += getColorVal(it->sn, it->fs, lsi);
  //   if(show) dnl(x);
  //   return x;
  // };
  // auto getCurrentColor = [&](int i)
  // {
  //   auto it1 = color[i].rbegin();
  //   if(block_color[i].empty()) return it1->sn;
  //   auto it2 = block_color[i].rbegin();
  //   if(it1->fs < it2->fs) return it2->sn;
  //   else return it1->sn;
  // };
  fr(t,0,q)
  {
    string s; cin >> s;
    if(s=="Color")
    {
      int l,r,c; cin >> l >> r >> c; l--, r--;
      st.setColor(l,r+1,c);
      // for(int i = l; i<=r;)
      // {
      //   int b = i/B;
      //   if(i%B==0 && (i+B-1)<=r)
      //   {
      //     if(!block_color[b].empty())
      //     {
      //       int x = getColorVal(block_color[b].rbegin()->sn, block_color[b].rbegin()->fs, t);
      //       x += block_update[b].rbegin()->sn;
      //       block_update[b][t] = x;
      //     }
      //     block_color[b][t] = c;
      //     i+=B;
      //   }
      //   else
      //   {
      //     int y = getCurrentValue(i, t);
      //     value[i][t] = y;
      //     color[i][t] = c;
      //     i++;
      //   }
      // }
    }
    else if(s=="Add")
    {
      int c,x; cin >> c >> x;
      // dnl(c);
      st.addToColor(c,x);
      // if(!update[c].empty()) x += update[c].rbegin()->sn;
      // update[c][t] = x;
      // csp("---");
      // dnl(update[c]);
    }
    else
    {
      int x; cin >>x; x--;
      // dsp(x), dsp(t); dnl(color[x]);
      // int y = getCurrentValue(x, t);
      // value[x][t] = y;
      // color[x][t] = color[x].rbegin()->sn;
      cnl(st.query(x));
    }

    vi values, colors;
    // if(t>=4)
    // {
    //   dnl(color[0]);
    //   dnl(value[0]);
    // }
    // st.printTree();
    // fr(i,0,n) values.pb(st.query(i));
    // csp("---VALUES---"); cnl(values);
    // fr(i,0,n) colors.pb(getCurrentColor(i));
    // csp("---COLORS  ---");  cnl(colors);
  }
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  // test(t)
  {
    solve();
  }
}
// curr state:
// color:  individual color, as well as set.
//         time: store time to determine which is current
//         individual change: add prev color val to value[i].
//         block change: add upd[col[b]]
//         O(B)
// value:
//     initial value 0
//     whenever you change colors, you update the value, for both individual and block.
//     O()
//
// update:
//     upd[c] = x;
//
// Query:
//     there's a block value and an individual value.
//     But, the current color also may have some value. Check
//
//
// 1.2d update matrix:
//     update[color][time] = total_val till time:
//     update[c][q_no] = update[c].rbegin()->sn + x
// 2. Fn to calculate update for color c from time t1 to time t2 getUpdate(c, t1, t2):
//       (--update[c].lb(t2))->sn - update[c].lb(t1)->sn;
// 3. value is value[i] + (value of color[i]) + (value of batch_color[i]) if (current_color == batch_color[i])
// 4. Store value of batch_color whenever it changes too.
