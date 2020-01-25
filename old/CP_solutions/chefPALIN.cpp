#include <bits/stdc++.h>
using namespace std;
int increment(string &str, int psn)
{
    int z=0;
    for (int i=0;i<psn+1;i++)
    {
      if (str[psn-i]=='9')
      {
        str[psn-i]='0';
        z++;
        continue;
      }
      else
      {
        str[psn-i]++;
        break;
      }
    }
    return z;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string str;
    cin >> str;
    int size=str.length();
    int f=1;
    for (auto x:str) {if (x!='9') {f=0; break;}}
    if (f)
    {
      for (int i=1;i<size;i++) str[i]='0';
      str[0]='1';
      str.push_back('1');
    }
    int mid=size/2;
    int flag=0;
    for(int i=0;(i<mid)&&(!f);i++)
      {
        char a=str[mid-i-1];
        char b=str[mid+i+(size%2)];
        if(a==b) {flag++; continue;}
        else
        {
          if(a>b)
          {
            str[mid+i+(size%2)]=a;
            for(int j=i+1;j<mid;j++) str[mid+j+(size%2)]=str[mid-j-1];
          }
          if(a<b)
          {
            increment(str,mid-i-1); str[mid-i]='0';
            for(int j=i;j<mid;j++) str[mid+j+(size%2)]=str[mid-j-1];
          }
          break;
        }
      }
    if (flag==(mid))
    {
      if (size%2)
      {
        int k=increment(str,mid);
        for (int i=1;i<=k;i++) str[mid+i]=str[mid-i];
      }
      else
      {
        int k = increment(str,mid);
        if (str[mid]!='0') increment(str,mid-1);
        else
        {
          for (int i=1;i<=k;i++) str[mid+i]=str[mid-i-1];
        }
      }
    }
    cout << str << endl;
  }
}
