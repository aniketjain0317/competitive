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
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);cout<<endl;}
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
int t1,b;

int main()
{
  cin >> t1 >> b;
  fr(tnox,0,t1)
  {
    int arr[4][b];
    int div10=b/10;
    fr(i,0,div10)
    {
      fr(j,0,5)
      {
        int ind=5*i+j;
        cnl(ind+1);
        cin >> arr[0][ind];
        cnl(b-ind);
        cin >> arr[0][b-ind-1];

        arr[1][i]=!arr[0][i];
        arr[2][i]=arr[0][b-i-1];
        arr[3][i]=!arr[0][b-i-1];

        arr[1][b-i-1]=!arr[0][b-i-1];
        arr[2][b-i-1]=arr[0][i];
        arr[3][b-i-1]=!arr[0][i];
      }
    }

    if(div10<=1)
    {
      string ans="";
      fr(i,0,b) {char x=arr[0][i]+48;ans+=x;}
      cnl(ans);
    }
    else if(div10<=50)
    {
      int ans2[b]={};
      fr(i,0,div10)
      {
        int x[2],k=0,f=0;
        int ind=i*10;
        cnl(ind+1);
        cin >> ans2[ind];
        fr(i,0,4) if(ans2[ind]==arr[i][ind]) x[k++]=i;
        fr(i,1,5) if(arr[x[0]][ind+i]==arr[x[1]][ind+i]) {f=i;break;}
        if(!f) fr(i,0,5) ans2[ind+i]=arr[x[0]][ind+i];
        else
        {
          cnl(ind+1+f);
          cin >> k;
          if(arr[x[0]][ind+f]==k) fr(i,0,5) ans2[ind+i]=arr[x[0]][ind+i];
          else fr(i,0,5) ans2[ind+i]=arr[x[1]][ind+i];
        }
      }

      string ans="";
      fr(i,0,b) {char x=ans2[i]+48;ans+=x;}
      cnl(ans);
    }
  }
}
