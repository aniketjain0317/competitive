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

const ll MOD = 998244353;
const ll INF = 1000000007;
const int N = 100005;

class classFFT
{
public:
  using cd = complex<double>;
  using vd = vector<double>;
  using vcd = vector<cd>;
  using vi = vector<int>;
  const double PI = acos(-1);

  // returns point form of poly a, with [1,w,w^2,...] as the points.
  void FFT(vcd &a, bool inv)
  {
    int n = a.size();
    if(n==1) return;

    vcd odd,even;
    for(int i = 0; i<n; i++)
    {
      if(i%2) odd.push_back(a[i]);
      else even.push_back(a[i]);
    }
    FFT(odd, inv); FFT(even, inv);

    double theta = 2*PI/n; if(inv) theta*=-1;
    cd w(cos(theta), sin(theta)), wi(1);

    for(int i = 0; 2*i<n; i++)
    {
      a[i] = even[i]+wi*odd[i];
      a[i+(n/2)] = even[i]-wi*odd[i];
      if(inv) a[i]/=2, a[i+(n/2)]/=2;
      wi*=w;
    }
  }


  vcd coeffToPoint(vd a, int n)
  {
    a.resize(n,0);
    vcd cdA(a.begin(),a.end());
    FFT(cdA, 0);
    return cdA;
  }

  vd PointToCoeff(vcd a)
  {
    int n = a.size();
    double theta = -2*PI/n;
    cd w(cos(theta), sin(theta)); w/=n;
    FFT(a, 1);
    vd ans(n);
    for(int i = 0; i<n; i++) ans[i] = round(a[i].real());
    return ans;
  }

  vd multiply(vd a, vd b)
  {
    int n = 1;
    while(n < a.size()+b.size()) n<<=1;
    vcd pointsA = coeffToPoint(a,n);
    vcd pointsB = coeffToPoint(b,n);
    vcd pointsAns(n);
    for(int i=0; i<n; i++) pointsAns[i] = pointsA[i]*pointsB[i];
    vd ans = PointToCoeff(pointsAns);
    while(!ans.empty() && !ans.back()) ans.pop_back();
    return ans;
  }

  vi multiply(vi a, vi b)
  {
    vd dA(a.begin(), a.end()), dB(b.begin(), b.end());
    vd dAns = multiply(dA, dB);
    vector<int> ans;
    for(auto x: dAns) ans.push_back(round(x));
    return ans;
  }
};


// CREDITS: CF - madhur4127
struct Modular {
  int value;
  int mod(int &v) {return (v % MOD + MOD)%MOD;}

  Modular(int v = 0) { value = mod(v);}
  Modular(int a, int b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value = value + b.value; value = mod(value); return *this;}
  Modular& operator-=(Modular const& b) {value = value - b.value; value = mod(value); return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value; value = mod(value); return *this;}

  friend Modular mexp(Modular a, int e)
  {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }

  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}

  friend Modular& operator++(Modular& a, intt) {return a += 1;}
  friend Modular operator++(Modular const& a, intt) {return Modular(a)++;}
  friend Modular& operator--(Modular& a, intt) {return a -= 1;}
  friend Modular operator--(Modular const& a, intt) {return Modular(a)--;}
};
typedef Modular mo;
using vmo = vector<mo>;

Modular binpow(Modular a, int e)
{
  Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
  return res;
}

class classNTT
{
public:
  using vi = vector<int>;
  using vmo = vector<mo>;
  const int MOD = 119<<23 + 1; //998244353
  int R = 2; // IDK
  // returns point form of poly a, with [1,w,w^2,...] as the points.
  void FFT(vmo &a, bool inv)
  {
    int n = a.size();
    if(n==1) return;

    vmo odd,even;
    for(int i = 0; i<n; i++)
    {
      if(i%2) odd.push_back(a[i]);
      else even.push_back(a[i]);
    }
    FFT(odd, inv); FFT(even, inv);

    int theta = (MOD-1)/n; if(inv) theta*=-1;
    while(theta<0) theta+=MOD-1;
    mo w(binpow(R,theta)), wi(1);

    for(int i = 0; 2*i<n; i++)
    {
      a[i] = even[i]+wi*odd[i];
      a[i+(n/2)] = even[i]-wi*odd[i];
      if(inv) a[i]/=2, a[i+(n/2)]/=2;
      wi*=w;
    }
  }


  vmo coeffToPoint(vmo a, int n)
  {
    a.resize(n,0);
    FFT(a, 0);
    return a;
  }

  vmo PointToCoeff(vmo a)
  {
    int n = a.size();
    FFT(a, 1);
    return a;
  }

  vmo multiply(vmo a, vmo b)
  {
    int n = 1;
    while(n < a.size()+b.size()) n<<=1;
    a.resize(n,0); b.resize(n,0);
    FFT(a,0); FFT(b,0);
    vmo ans(n);
    for(int i=0; i<n; i++) ans[i] = a[i]*b[i];
    FFT(ans,1);
    while(!ans.empty() && ans.back()==0) ans.pop_back();
    return ans;
  }

  vmo multiply(vi a, vi b)
  {
    vmo moA(a.begin(), a.end()), moB(b.begin(), b.end());
    return multiply(moA, moB);
  }
};

intt main()
{
  cout.precision(numeric_limits<double>::max_digits10);
  vector<int> a({1,2,1});
  vector<int> b({1,-2,1});
  classNTT f;
  for(int i = 2; i<=100005; i++)
  {
    f.R = i;
    vmo ans = f.multiply(a,b);
    if(i%1000==0) cnl(i);
    if(ans[0]==1) csp("MIL GYA"), cnl(i);
  }
  // for(auto x: ans) cout << x << " "; cout << endl;
}
