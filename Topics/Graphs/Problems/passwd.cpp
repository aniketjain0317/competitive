// Problem 1263D (dfs and similar / 1500 / posting on ACM slack channel by Siddhart)
// Solved (this is the unoptimized solution)
#include <bits/stdc++.h>
using namespace std;
#define NO 200000
int n;

vector <int> graph[NO+256];
int visited[NO+256]={};
int cnt;
void dfs(int);

int main()
{
  cin >> n;
  for(int i=0;i<n;i++)
  {
    string s;
    char prev;
    cin >> s;
    for(char a: s)
    {
      graph[i].push_back(NO+a);
      graph[NO+a].push_back(i);
    }
  }
  for(int i=NO;i<NO+256;i++)
  {
    if(graph[i].size()&&!visited[i])
    {
      dfs(i);
      cnt++;
    }
  }
  cout << cnt;
}

void dfs(int node)
{
  visited[node]=1;
  for(int child: graph[node])
  {
    if(!visited[child])
    {
      dfs(child);
    }
  }
}
