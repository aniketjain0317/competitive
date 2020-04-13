// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 200000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int dist[N+1]={};
int ch[N+1]={};
int visited[N+1]={};
vi adj[N+1];
int n;
vi arr;

void bfs(int);
int main()
{
  int n; cin >> n;
  arr.assign(n,0);
  fr(i,0,n-1)
  {
    int t1, t2; cin >> t1 >> t2;
    adj[t1].pb(t2);
    adj[t2].pb(t1);
  }
  bfs(1);
  cinp(n,arr);


  queue<int> ch;
  fr(i,0,n)
  {
    int node = arr[i];
    for(int child: adj[node])
    {

    }
  }
}

void bfs(int first)
{
  queue<int> q;
  visited[first]=1;
  ch[0]=1;
  q.push(first);
  while(!q.empty())
  {

    int node = q.front();
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        dist[child]=dist[node]+1;
        ch[dist[child]]+=1;
        q.push(child);
        visited[child]=1;
      }
    }
    q.pop();
  }
}
