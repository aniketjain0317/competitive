// Calculates height for all subtrees
//Complete

/*
n - number of nodes
root - root node
a,b - a is the parent of b (n-1 edges)
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define cnl(x) cout << x << endl
#define fr(i,x,y) for(int i=x;i<y;i++)
#define N 100000
typedef vector<int> vi;

vi adj[N];
int height[N]={};

int calcHeight(int node);
int main()
{
  int n; cin >> n;
  int root; cin >> root;
  fr(i,0,n-1)
  {
    int a,b; cin >> a >> b;
    adj[a].pb(b);
  }

  cnl(calcHeight(root));
}

int calcHeight(int node)
{
  vi possible; possible.pb(-1);
  for(auto child: adj[node])
  {
    possible.pb(calcHeight(child));
  }
  height[node]= *max_element(possible.begin(),possible.end())+1;
  return height[node];
}
