// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);} cout << endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

char convToBool(char c) {return (c=='T');}
char convToStr(bool b) {return b?'T':'F';}
bool strcheck(string str)
{
  char c1=str[0];
  char c2=str[1];
  char c3 = str[2];
  bool b1 = (c1=='T');
  bool b2 = (c2=='T');
  if(c2=='&') return b1&b2;
  if(c2=='|') return b1|b2;
  if(c2=='^') return b1^b2;
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test(t)
  {
    int n; cin >> n;
    int k =(n-1)/2;
    string str; cin >> str;
    cout << endl;
    int t[k]={},f[k]={};
    for(int i=0;i<k;i++)
    {
      string s= str.substr(2*i+1,2);
      string s1=str[2*i]+s;
      bool a = strcheck(s1);
      if(!i)
      {
        if(a) t[i]++;
        else f[i]++;
        continue;
      }
      string s2='T'+s;
      string s3='F'+s;
      bool chT = strcheck(s2), chF=strcheck(s3);
      if(chT) t[i]+=t[i-1];
      else  f[i]+=t[i-1];
      if(chF) t[i]+=f[i-1];
      else f[i]+=f[i-1];


      string s4 = "T" + string(1,str[2*i-1])+convToStr(a);
      string s5 = "F" + string(1,str[2*i-1]) + convToStr(a);
      bool dt = strcheck(s4);
      bool df = strcheck(s5);

      int x1=0, x2=0;
      if(i==1)
      {
        if(str[0]=='T') x1=1;
        else x2=1;
      }
      else {x1=t[i-2];x2=f[i-2];}

      if(dt) t[i]+=x1;
      else f[i]+=x1;
      if(df) t[i]+=x2;
      else f[i]+=x2;

      if(i==2)
      {
        cnl(s1);cnl(a); cnl(s2);cnl(s3);cnl(s4);cnl(s5);
      }
    }
    show1d(k,t);
    show1d(k,f);
  }
}
