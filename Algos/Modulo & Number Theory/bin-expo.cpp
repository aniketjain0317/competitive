long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

mo binpow(mo a, long long b) {
    mo res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


ll pow(ll a, ll e)
{
  ll ans = 1;
  for(; e; e>>=1)
  {
    if(e&1) ans = ans*a;
    a = a*a;
  }
  return ans;
}

// modular
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mm(res, a);
        a = mm(a,a);
        b >>= 1;
    }
    return res;
}
