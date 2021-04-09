// Problem 377A - Codeforces (dfs and similar / 1600)
// Solved (Note that arr size at 500 was causing WA on T8)
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[600][600]={};
int visited[600][600]={};
void dfs(int,int);
int main()
{
  cin >> n >> m >> k;
  int first[2]={-1,-1};
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      char t;
      cin >> t;
      if(t=='.')
      {
        if(first[0]==-1)
        {
          first[0]=i;
          first[1]=j;
        }
        arr[i][j]=1;
      }
      if(t=='#') arr[i][j]=2;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]==1)
      {
        dfs(i,j); break;
      }
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]==1) cout << '.';
      if(arr[i][j]==2) cout << '#';
      if(arr[i][j]==3) cout << 'X';
    }
    cout << endl;
  }
}

void dfs(int i, int j)
{
  visited[i][j]=1;
  vector<int>c1;
  vector<int>c2;
  if(arr[i][j+1]==1&&!visited[i][j+1])
  {
    dfs(i,j+1);
    c1.push_back(i);
    c2.push_back(j+1);
  }
  if(arr[i+1][j]==1&&!visited[i+1][j])
  {
    dfs(i+1,j);
    c1.push_back(i+1);
    c2.push_back(j);
  }
  if(arr[i][j-1]==1&&!visited[i][j-1])
  {
    dfs(i,j-1);
    c1.push_back(i);
    c2.push_back(j-1);
  }
  if(arr[i-1][j]==1&&!visited[i-1][j])
  {
    dfs(i-1,j);
    c1.push_back(i);
    c2.push_back(j-1);
  }
  if(k)
  {
    arr[i][j]=3;
    k--;
  }
}
