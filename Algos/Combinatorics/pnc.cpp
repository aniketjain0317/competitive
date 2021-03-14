ll binomialCoeff(int n, int k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll fac[N]={};
ll calcFac(int n)
{
  fac[0]=1;
  frr(i,1,n) fac[i]=mm(fac[i-1],i);
}

ll ncr(int n, int r)
{
  if(r>n) return 0;
  return dm(fac[n], mm(fac[r], fac[n-r]));
}
