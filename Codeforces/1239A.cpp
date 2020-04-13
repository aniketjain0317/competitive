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
    reverse(pairt,pairt+n);
    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m; cin >> n >> m;
  int arr[m];
  cinp(m,arr);

  int s = accumulate(arr,arr+m,0);
  int l = 0, ans[m]={};
  if(s<n) {cnl(-1);return 0;}
  else l=s-n;
  int ind[m];
  fr(i,0,m) ind[i]=i;
  pairsort(arr,ind,m);

  ans[ind[0]]=1;
  int x_start =1, x_end=arr[0];
  fr(i,1,m)
  {
    if(l>=arr[i-1]-1)
    {
      x_start+=1;
      l-=arr[i-1]-1;
    }
    else if(l>0)
    {
      x_start+=(arr[i-1]-l);
      l=0;
    }
    else if(l==0)
    {
      x_start=x_end+1;
    }
    ans[ind[i]]=x_start;
    x_end=x_start+arr[i]-1;

    if(x_end>n) {cnl(-1);return 0;}
  }
  fr(i,0,m) csp(ans[i]);
}
