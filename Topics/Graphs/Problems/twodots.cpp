//Problem 510B - Codeforces (dfs and similar / 1500) (different kind of dfs)
//Solved (forgot to update visited)
#include <bits/stdc++.h>
using namespace std;
int n,m,flag=0;
int visited[500][500]={};
char matrix[500][500]={};
void dfs(int, int);
int main()
{
  cin >> n >> m;
  for (int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      char t;
      cin >> t;
      matrix[i][j]=t;
    }
  }
  for (int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(!visited[i][j]) {visited[i][j]=1; dfs(i,j);}
      if(flag) break;
    }
    if(flag) break;
  }
  if(flag) cout << "Yes";
  else cout << "No";
}


void dfs(int node1, int node2)
{
  int c=0;
  char x = matrix[node1][node2];
  int a = node1, b = node2;
  visited[node1][node2]=1;
  if(matrix[node1+1][node2]==x)
  {
    if(!visited[node1+1][node2])
    {
      dfs(a+1,b);c--;
    }
    else c++;
  }
  if(matrix[node1][node2+1]==x&&!flag)
  {
    if(!visited[node1][node2+1])
    {
      dfs(a,b+1);c--;
    }
    else c++;
  }
  if(matrix[node1-1][node2]==x&&!flag)
  {
    if(!visited[node1-1][node2])
    {
      dfs(node1-1,node2);c--;
    }
    else c++;
  }
  if(matrix[node1][node2-1]==x&&!flag)
  {

    if(!visited[node1][node2-1])
    {
      dfs(node1,node2-1);c--;
    }
    else c++;
  }
  if(c>1) {flag = 1;}
}
