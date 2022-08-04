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

void pairsort(int a[], int b[], int n)
{
    pair<int, int> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}


int main()
{
  test(t)
  {
    int n; cin >> n;
    int start[n], end[n], num[n];
    char ans[n];
    fr(i,0,n) num[i]=i;
    fr(i,0,n) cin >> start[i] >> end[i];
    pairsort(start,num,n);
    int x1=-1,x2=-1,flag=0;
    fr(i,0,n)
    {
      if(x1!=-1) if(start[i]>=end[num[x1]]) x1=-1;
      if(x2!=-1) if(start[i]>=end[num[x2]]) x2=-1;
      if(x1==-1) {x1=i; ans[num[i]]='C';}
      else if(x2==-1) {x2=i; ans[num[i]]='J';}
      else {flag=1;break;}
    }

    cout << "Case #"<< tno << ": ";
    if(flag) cnl("IMPOSSIBLE");
    else
    {
      string s;
      fr(i,0,n) s+=ans[i];
      cnl(s);
    }
  }
}
