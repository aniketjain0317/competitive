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
#define N 200001
#define R 27

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
  test(t)
  {
    ainp(n,arr);

    int count[R]={};
    fr(i,0,n) count[arr[i]]++;
    int ind[R];
    fr(i,0,R) ind[i]=i;
    // pairsort(count,ind,R);
    int c2[R][R]={};

    int j[R]={};
    fr(i,0,R) j[i]=n-1;
    int dp[R][R]={};
    int len[R]={};
    int mxm=0;
    fr(i,0,n)
    {
      int x = arr[i];
      len[x]++;
      fr(j,0,R) c2[j][x]++;
      if(2*len[x] > count[x]) continue;
      while(arr[j[x]]!=x)
      {
        c2[x][arr[j[x]]]++;
        j[x]--;
      }
      if(j[x]==i) continue;
      fr(k,1,R)
      {
        int y = dp[x][k];
        int z=max(y,(2*len[x]+count[k]-c2[x][k]));
        if(x==k) z=0;
        dp[x][k]=z;
        if(z>mxm) mxm=z;
      }
    }
    fr(i,0,R) if(mxm<count[i]) mxm=count[i];
    cnl(mxm);
  }
}
