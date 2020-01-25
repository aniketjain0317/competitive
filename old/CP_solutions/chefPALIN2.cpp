#include <bits/stdc++.h>
using namespace std;
string palin (string str)
{
  string ans=str;
  int size=ans.length(), mid=size/2;
  for (int i=0;i<mid;i++) ans[mid+i+(size%2)]=ans[mid-i-1];
  return ans;
}

void inc (string &str, int psn)
{
  for (int i=0;i<psn+1;i++)
  {
    if (str[psn-i]=='9')
    {
      str[psn-i]='0';
      continue;
    }
    else
    {
      str[psn-i]++;
      break;
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    string ans=str;
    int size=str.length(), mid=size/2 ;
    int f=0;
    for (auto x:str) {if (x!='9') {f=1; break;}}
    if (!f)
    {
      for (int i=1;i<size;i++) ans[i]='0';
      ans[0]='1';
      ans.push_back('1');
    }
    while(f)
    {
      ans=palin(ans);
      if (ans<=str)
        {
          inc(ans,mid-1+(size%2)); ans=palin(ans);
        }
      else break;
    }
    cout << ans << endl;
  }
}
