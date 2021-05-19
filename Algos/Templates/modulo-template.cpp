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

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mm(res, a);
        a = mm(a,a);
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a)
{
  return binpow(a,INF-2);
}
