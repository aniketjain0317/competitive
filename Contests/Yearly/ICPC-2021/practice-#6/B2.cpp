#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)

using namespace std;


void read(int n,vector<int>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }

}
void read(int n,int m,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n,vector<int>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<m;j++)
            cin>>x[i][j];
    }
}
void read(int n,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<n-1;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<vector<int>>& x,int m)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<m;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<ll>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
}


vector<long long>isprime(100005 , true);
vector<long long>prime;
vector<long long>SPF(100005);

// function generate all prime number less then N in O(n)
ll findMinNumber(ll n)
{
    int count = 0, ans = 1;

    // Since 2 is only even prime, compute its
    // power seprately.
    while (n%2 == 0)
    {
        count++;
        n /= 2;
    }

    // If count is odd, it must be removed by dividing
    // n by prime number.
    if (count%2)
        ans *= 2;

    for (int i = 0; prime[i] <= sqrt(n); i++)
    {
        count = 0;
        while (n%prime[i] == 0)
        {
            count++;
            n /= prime[i];
        }

        // If count is odd, it must be removed by
        // dividing n by prime number.
        if (count%2)
            ans *= prime[i];
    }

    if (n > 2)
        ans *= n;

    return ans;
}
void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false ;

    // Fill rest of the entries
    for (long long int i=2; i<N ; i++)
    {
        // If isPrime[i] == True then i is
        // prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);

            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }

        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;

            // put smallest prime factor of i*prime[j]
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
	manipulated_seive(100005);
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n;
		vector<ll> v;
		read(n,v);
		vector<ll> x(v.begin(),v.end());
		sort(all(x));
		unordered_map<ll,ll> mp;
		int flag = 0;
		for(int i = 0;i<n;i++){
			ll z = findMinNumber(v[i]);
			mp[v[i]] = z;
		}
		for(int i = 0;i<n;i++){
			if(mp[v[i]] != mp[x[i]]){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}

    }
    return 0;
}
