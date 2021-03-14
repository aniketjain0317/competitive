ll gcd(ll a,ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
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
