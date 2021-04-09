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
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

struct item{
    int val;
};

struct segtree{


    int size;
    int mod;

    vector<item> values;


    item NEUTRAL_E = {0};

    item merge(item a,item b)
    {
        return {(a.val + b.val)%mod};
    }

    item single(int a)
    {
        return{a%mod};
    }

    void init(int n,int modu)
    {
        size = 1;
        mod = modu;
        while(size < n)
        {
            size *= 2;
        }
        values.resize(4*size,NEUTRAL_E);
    }

    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx - lx == 1)
        {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m)
        {
            set(i,v,2*x + 1,lx,m);
        }
        else
        {
            set(i,v,2*x + 2,m,rx);
        }

        values[x] = merge(values[2*x + 1],values[2*x + 2]);

    }

    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    void print(item a)
    {
        cout<<a.val<<endl<<endl;
    }
    item calc(int l,int r,int x,int lx,int rx)
    {
        if(lx >= r || l >= rx)
        {
            return NEUTRAL_E;
            //print(NEUTRAL_E);
        }
        if(lx >=l && rx <=r)
        {
            return values[x];
            //print(values[x]);
        }
        int m = (lx+rx)/2;
        auto s1 = calc(l,r,2*x+2,m,rx);
        auto s2 = calc(l,r,2*x+1,lx,m);
        // print(s1);
        // print(s2);
        return merge(s2,s1);
    }
    item calc(int l,int r)
    {
        return calc(l,r,0,0,size);
    }

    void print()
    {
        for(int i = 0;i<values.size();i++)
            cout<<values[i].val<<endl<<endl;
    }

};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    int n,q;
    int s[n], f[n];
    fr(i,0,n)
    {
      char c; cin >> c;
      s[i]=(c=='1');
    }
    fr(i,0,n)
    {
      char c; cin >> c;
      f[i]=(c=='1');
    }
  }
}
