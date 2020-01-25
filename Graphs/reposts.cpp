// Problem 522A - Codeforces (dfs and similar / 1700)
// Solved (dfs)
#include <bits/stdc++.h>
using namespace std;

int cim(string s1, string s2) {
   //convert s1 and s2 into lower case strings
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   if(s1.compare(s2) == 0)
      return 1; //The strings are same
   return 0; //not matched
}

int n;
vector <string> users;
vector <int> graph[300];
int visited[300]={};
int pop[300]={};
int ans=1;

void dfs(int);
int main()
{
  cin >> n;
  for(int i=0;i<n;i++)
  {
    string s1,s2,s3;
    int a1=-1, a3=-1;
    cin >> s1 >> s2 >> s3;
    int x=0;
    for (string s: users)
    {
      if(cim(s3,s)) a3=x;
      else if(cim(s1,s)) a1=x;
      x++;
    }
    if(a3==-1) {a3=users.size(); users.push_back(s3);}
    if(a1==-1) {a1=users.size(); users.push_back(s1);}
    graph[a3].push_back(a1);
  }
  dfs(0);
  cout << ans;
}


void dfs(int node)
{
  visited[node]=1;
  if(!node) pop[node]=1;
  for(int child: graph[node])
  {
    if(!visited[child])
    {
      visited[child]=1;
      pop[child]=pop[node]+1;
      ans= max(ans,pop[child]);
      dfs(child);
    }
  }
}
