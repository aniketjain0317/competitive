#define am(a,b) MOD(MOD(a)+MOD(b))
#define mm(a,b) MOD(MOD(a)*MOD(b))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

ll MOD(ll a)
{
  a = a%INF;
  while(a<0) a+=INF;
  return a;
}

// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
  if (b == 0) {
      x = 1;
      y = 0;
      return a;
  }
  ll x1, y1;
  ll d = gcdExtended(b, a % b, x, y);
  x1 = y;
  y1 = x - y * (a / b);
  return d;
}

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, x, y);
    if (g != 1)
      return 0;
    else
    {
        // m is added to handle negative x
        ll res = (x % m + m) % m;
        return res;
    }
}
