#include "bits/stdc++.h"
using namespace std;
int n,flag=0;
list <char> order;
void fn(int,int,int);
void arrange(char,char,int);
string arr[200];
int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> arr[i];
  for(char a='a';a<='z';a++) order.push_back(a);
  fn(0,0,0);
  fn(0,0,0);
  fn(0,0,1);
  if(flag) cout << "Impossible\n";
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

void fn(int t,int no, int check)
{
  if(t>50||no>100) return;
  if(arr[no].size()>t)
  {
    char prev=arr[no][t];
    for(int i=no+1;i<n;i++)
    {
      if(flag) return;
      if(arr[i].size()<=t) continue;
      char x=arr[i][t];
      if(t&&arr[i][t-1]!=arr[i-1][t-1]) return;
      if(x==prev)
      {
        if(arr[i].size()<arr[i-1].size()) {flag=1; return;}
        else fn(t+1,i-1,check);
      }
      else
      {
        arrange(x,prev,check);
        prev=x;
      }
    }
  }
}
