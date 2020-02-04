#include "bits/stdc++.h"
using namespace std;
int n,flag=0;
int visited[128]={};
int cmp[128]={};
vector<char> adj[128];
string arr[101];
vector<char>ans;
void dfs(char);
void fn(int,int);
int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> arr[i];
  for(int i=1;i<n;i++)
  {
    char p=arr[i-1][0];
    char c = arr[i][0];
    if(c==p)
    {
      fn(0,i);
    }
    else
    {
      adj[p].push_back(c);
    }
  }

  for(char a='a';a<='z';a++)
  {
    if(!visited[a]) dfs(a);
    if(flag) break;
  }
  reverse(ans.begin(),ans.end());
  if(flag) cout << "Impossible";
  else for(char a: ans) cout << a;
}

void fn(int t, int no)
{
  for(int i=no;i<n;i++)
  {
    if(arr[i][t-1]!=arr[i-1][t-1]) return;
    if(arr[i-1].size()<=t) continue;
    if(arr[i].size()<=t) {flag=1;break;}
    char p=arr[i-1][t];
    char c=arr[i][t];
    if(p==c) fn(t+1,i);
    else
    {
      adj[p].push_back(c);
    }
  }
}

void dfs(char node)
{
  visited[node]=1;
  for(char child: adj[node])
  {
    if(!cmp[child])
    {
      if(!visited[child]) dfs(child);
      else {flag=1;return;}
    }
  }
  ans.push_back(node);
  cmp[node]=1;
}
