int gcd(int a,int b) {return a ? gcd(b % a, a) : b;}

int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
        if(result == 1) return 1;
    }
    return result;
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int &x, int &y)
{
  if (b == 0) {
      x = 1;
      y = 0;
      return a;
  }
  int x1, y1;
  int d = gcdExtended(b, a % b, x, y);
  x1 = y;
  y1 = x - y * (a / b);
  return d;
}

// Function to find modulo inverse of a
int modInverse(int a)
{
    int x, y;
    int g = gcdExtended(a, MOD, x, y);
    if (g != 1)
      return 0;
    else
    {
        int res = (x % MOD + MOD) % MOD;
        return res;
    }
}
