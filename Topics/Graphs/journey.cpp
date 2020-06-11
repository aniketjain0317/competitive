//Problem 839C - Codeforces (dfs and similar / 1500)
//WA on Test 6 (idk why)
// Solved now (wasnt before cuz of setprecision apparently)
#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> tree[100000];
vector <int> visited;
vector <long double> prob;
vector <int> length;
long double ans=0;

void dfs(int);
int main()
{
  cin >> n;
  visited.assign(n,0);
  prob.assign(n,0);
  length.assign(n,0);
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    tree[a-1].push_back(b-1);
    tree[b-1].push_back(a-1);
  }
  length[0]=0;
  prob[0]=1;
  dfs(0);
  cout << fixed << setprecision(7) << ans << '\n'; // This is the line which made the answer correct.
}

void dfs(int node)
{
  visited[node]=1;
  long double x = 1;
  if(!node) {x = tree[node].size();}
  else {x = tree[node].size()-1;}
  long double p = 1/x;
  for(int child: tree[node])
  {
    if(!visited[child])
    {
      prob[child]=prob[node]*p;
      length[child]=length[node]+1;
      if(tree[child].size()==1) {ans += prob[child]*length[child];}
      else {dfs(child);}
    }
  }
}
