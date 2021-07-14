#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> isprime(N, true);
vector<int> primes;
vector<int> SPF(N);

void sieve(int n)
{
  isprime[0] = isprime[1] = false;
  for(int i = 2; i<n; i++)
  {
    if(isprime[i])
    {
      primes.push_back(i);
      SPF[i] = i;
    }

    for(int j = 0; j < (int)primes.size() && primes[j]<SPF[i] && i*primes[j]<=n; j++)
    {
      isprime[i*primes[j]] = false;
      SPF[i*primes[j]]=primes[j];
    }
  }
}

int factorize(int n)
{
  vector<int> ans;
  for(auto &p: primes)
  {
    if(p>n) break;
    while(n%p==0) n/=p, ans.push_back(p);
  }
  if(n>1) ans.push_back(n);
  map<int, int> mp;
  for(auto x: ans) mp[x]++;
  int cnt = 1;
  for(auto p: mp) cnt *= (p.second+1);
  return cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  sieve(N-1);
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int x = factorize(n);
    cout << x << " ";
    if(x&1) cout << "BOB" << endl;
    else cout << "ALICE" << endl;
  }
}
