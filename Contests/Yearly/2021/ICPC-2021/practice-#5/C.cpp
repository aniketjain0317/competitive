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
ll power(ll a, ll b)    //a is base, b is exponent
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2 == 1)
		return (power(a,b-1)*a)%mod;
	ll q = power(a,b/2);
	return (q*q)%mod;
}
void DFS(int x,vector<vector<ll>>& adj,vector<ll>& val,vector<ll>& vis){
	vis[x] = val[x];
	for(auto it : adj[x]){
		if(vis[it] == -1){
			DFS(it,adj,val,vis);
			vis[x] = max(vis[x],vis[it]);
		}
			
	}
	return vis[x];
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        ll n,m;
		cin>>n;
		vector<vector<ll>> adj(n);
		for(int i = 0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		vector<ll> val(n);
		read(n,val);
		// for(int i = 1;i<n;i++)
		int index = max_element(all(val)) - val.begin();
		// index++;
		vector<ll> vis(n,-1);
		ll x = DFS(index,adj,val,vis);

		// cout<<x<<endl;
		ll sum = 0;
		for(int i = 0;i<n;i++){
			cout<<val[index] - vis[i]<<endl;
			// cout<<vis[i]<<" ";
		}
		ll edges = n-1;
		ll denom = power(edges,mod - 2)%mod;
		// cout<<((sum * denom)%mod + mod)%mod<<endl;
		// cout<<endl;
    }

    return 0;
}
