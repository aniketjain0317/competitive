// Problem 510C - Codeforces (dfs and similar / topological sort / 1800)
// WA on Test 12(idk why)(a messier solution not done using graphs)
#include "bits/stdc++.h"
using namespace std;
int flag=0;
list <char> order;
void arrange(char,char,int);
int main()
{
  int n;
  cin >> n;
  string arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];
  vector <int> posn[50];
  vector <char> given[50];
  char prev='9';
  for(char a='a';a<='z';a++) order.push_back(a);
  for(int i=0;i<n;i++)
  {
    char x = arr[i][0];
    if(x==prev&&(!posn[0].size()||(posn[0].back()!=i-2))) posn[0].push_back(i-1);
    else if(x!=prev)
    {
      given[0].push_back(x);
      prev=x;
    }
  }
  int v=1;
  for(int t=1;t<50;t++)
  {
    for(int no: posn[t-1])
    {
      char prev=0;
      for(int i=no;i<n;i++)
      {
        if(arr[i].size()<=t) {continue;}
        char x = arr[i][t];
        if(i==no);
        else if(arr[i][t-1]!=arr[i-1][t-1]) break;

        if(x==prev&&(posn[t].back()!=i-2)) posn[t].push_back(i-1);
        else if(x!=prev)
        {
          given[v].push_back(x);
        }
      }
      v++;
    }
  }
  for(int t=0;t<3;t++)
  {
    for(int i=0;i<v;i++)
    {
      for(int j=1;j<given[i].size();j++)
      {
        int k=0;
        if(t==2) k=1;
        arrange(given[i][j],given[i][j-1],k);
        if(flag) break;
      }
      if(flag) break;
    }
    if(flag) break;
  }
  if(arr[0]=="adjcquqdqcsvixgwglwrrmkhdsbebbjvcgz")
  {
    for(int i=0;i<v;i++)
    {
      for(int j=0;j<given[i].size();j++)
      {
        cout << given[i][j] << " ";
      }
      cout << endl;
    }
  }
  if(flag) cout << "Impossible";
  else for(auto it = order.begin();it!=order.end();it++) cout << *it;
}

void arrange(char a, char b, int check)
{
  auto iterA = order.end();
  auto iterB = order.end();
  int i=-1,j=-1,n=0;
  for(auto it = order.begin();i==-1||j==-1;it++)
  {
    if(*it==a) {iterA=it; i=n;}
    if(*it==b) {iterB=it; j=n;}
    n++;
  }
  if(i<j)
  {
    if(check) {flag=1; return;}
    iterB++;
    order.insert(iterB,a);
    order.erase(iterA);
  }
}
