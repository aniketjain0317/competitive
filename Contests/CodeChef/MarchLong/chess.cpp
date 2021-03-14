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
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

vi board[64];
int visited[64]={};
stack <int> moves;
int cnt=0;

void dfs(int node);
void showstack(stack <int> s)
{
  int sz = s.size();
  int m[sz];
    fr(i,0,sz)
    {
        int b = s.top();
        m[sz-i-1]=b;
        s.pop();
    }
    fr(i,1,sz)
    {
      int a = m[i];
      csp(a/8+1); cnl(a%8+1);
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fr(i,0,64)
  {
    int a = i/8 -i%8;
    fr(j,0,64) if(j/8-j%8==i/8-i%8 || j/8+j%8==i/8+i%8)
    {
      if(j==i) continue;
      board[i].pb(j);
    }
  }

  test(t)
  {
    int a,b; cin >> a >> b;
    int x = (a-1)*8+b-1;
    dfs(x);
    cnl(moves.size()-1);
    showstack(moves);
  }

}

void dfs(int node)
{
  visited[node]=1;
  moves.push(node);
  cnt++;
  if(cnt==32&&moves.size()<64) return;
  for(auto child: board[node])
  {
    if(cnt==32&&moves.size()<64) return;
    if(!visited[child])
    {
      dfs(child);
    }
  }
  if(cnt==32&&moves.size()<64) return;
  moves.pop();
  cnt--;
  visited[node]=0;
}
