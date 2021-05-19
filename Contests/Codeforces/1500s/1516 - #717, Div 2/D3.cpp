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
#define M_PI_2     1.57079632679489661923
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
#define int long long
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;
const long long MAX_SIZE = 1000001;

vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
struct item
{
  int val;
};

struct SegTree
{
  int n;
  int h;
  int size;
  vector<item> tree;
  vector<pi> len;

  // CHANGE NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = INT_MIN;
  item merge(item a, item b)
  {
    return {max(a.val,b.val)};
  }

  item single(int v)
  {
    return {v};
  }

  void init(int sz, int arr[])
  {
    // init size
    n = sz;
    h = ceil(log2(n))+1;
    size = 1LL<<(h-1);

    // init tree
    tree.resize(2*size, single(NEUTRAL));
    fr(i,0,n) update(i, arr[i]);

    // init len
    len.resize(2*size, {0,size});
    fr(x,1,size)
    {
      int l = len[x].fs, r = len[x].sn;
      int m = (l+r)/2;
      len[2*x]={l,m};
      len[2*x+1]={m,r};
    }
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i, int v)
  {
    int x = size + i;
    tree[x] = single(v);
    while(x>>=1)
      tree[x] = merge(tree[2*x], tree[2*x+1]);
  }

  // [l,r), [lx, rx), 0-indexed
  item query(int l, int r, int x=1)
  {
    int lx = len[x].fs, rx = len[x].sn;
    if(lx>=l && rx<=r) return tree[x];
    if(rx<=l || lx>=r) return single(NEUTRAL);

    item left = query(l, r, 2*x);
    item right = query(l, r, 2*x+1);
    return merge(left, right);
  }

  int find(int k, int l, int x = 1)
  {
    int lx = len[x].fs, rx = len[x].sn;

    if(tree[x].val<k) return -1;
    if(rx<=l) return -1; // ADDED EXTRA CONDITION
    if(x>=size) return x-size;

    int ans = find(k,l,2*x);
    if(ans==-1) ans = find(k,l, 2*x+1);

    return ans;
  }

  void printTree()
  {
    cnl("TREEEEEEEEE: ");
    frr(k,1,h)
    {
  // CHANGE THIS IF ITEM.V CANNOT BE PRINTED
      fr(i,1<<(k-1), 1<<k) csp(tree[i].val);
      cout << endl;
    }
    cout << endl;
  }
};

void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
    for (ll i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (ll j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}


intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  manipulated_seive(N);
  int n; int q; cin >> n >> q;
  int arr[n+1]={};
  frr(i,1,n) cin >> arr[i];

  map<int,int> mp;
  int csl[n+1]={};
  frr(i,1,n)
  {
    int x = arr[i];
    while(x>1)
    {
      int y = SPF[x];
      while(x%y==0) x/=y;
      if(mp[y]>0) mxs(csl[i],mp[y]);
      mp[y]=i;
    }
  }
  SegTree st; st.init(n+1, csl);

  vi parts;
  int pref[n+1]={};
  parts.pb(1);
  frr(i,1,n) if(csl[i]>=parts.back()) parts.pb(i);
  parts.pb(n+1);
  int tt = parts.size();
  fr(i,0,tt-1) fr(j, parts[i], parts[i+1])
      pref[j]=i;

  fr(i,0,q)
  {
    int l, r; cin >> l >> r;
    int a1=-1, a2=-1;
    int ans = pref[r] - pref[l] + 1;
    a1 =ans;
    if(ans==1) {cnl(ans); continue;}

    int fnew = st.find(l,l);
    ans -= pref[fnew-1] - pref[l];
    a2 =ans;
    if(ans>2)
    {
      int tryr = max(fnew, parts[pref[r]-1]);
      int lnew = st.find(tryr, tryr);
      ans-=pref[tryr] - pref[lnew-1];
    }
    if(i==6 && ans==20)
    {
      vshow1d(parts);
      csp(l); csp(r); csp(fnew); csp(parts[pref[l]]);
    }
    cnl(ans);
  }
}
// 1 358 1215 2461 3440 4374 5097 5259 5515 6513 6572 8292 9439 11214 12402 12923 14502 16353 16833 18339 19507 20924 23233 24285 25991 26260 26390 28442 28926 29636 30982
// 32186 32485 34388 34735 35227 35484
// 36725 37490 38908 39041 40149 41642 42445 45255 46065 46630 48571 50616 51277 52916 54492 55406 56556 57223 58235 58950 59777 61586
// 63592 64748 67135 67945 69318 70237
// 71272 73213 73720 74968 75946 77852 79219 81086 83179 83948 84708 85630 87234 88157 88608 88662 89602 90294 90886 9...
