#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
// #define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
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

struct comp{
	bool operator()(pair<int,int> a,pair<int,int> b) {
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
		int n;
        cin>>n;
		vector<pair<int,int>> v(n);
		for(int i = 0;i<n;i++){
			cin>>v[i].first>>v[i].second;
		}
		sort(all(v));
		int curr = 0;
		int ans = 0;
		priority_queue<int,vector<int>,greater<int>> pq;
		int i = 0;
		while(i < n){
			
			while(!pq.empty() && curr < v[i].first){
				while(!pq.empty() && pq.top() < curr){
					pq.pop();
				}
				if(!pq.empty()){
					curr++;
					pq.pop();
					ans++;
				}
				else{
					curr = v[i].first;
				}
			}
			int x =  v[i].first;
			while(i < n && v[i].first == x){
				pq.push(v[i].second);
				i++;
			}
		}
		while(!pq.empty()){
			while(!pq.empty() && pq.top() < curr){
				pq.pop();
			}
			if(!pq.empty()){
				curr++;
				pq.pop();
				ans++;
			}
		}
		cout<<ans<<endl;
    }

    return 0;
}
