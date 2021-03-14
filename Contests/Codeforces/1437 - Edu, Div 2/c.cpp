// Problem
//

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1e5
#define INF 1e9+5

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(q)
  {
    ainp(n,arr);
    int visited[500]={};
    vi diff[201];
    int cnt[201]={};
    int ans=0;
    int mxcnt = 10;
    int indx[201]={};
    fr(i,0,n) cnt[arr[i]]+=1;
    fr(i,1,201) if(cnt[i])
    {
      if(cnt[i]>mxcnt) mxcnt=cnt[i];
      visited[i]=1;
      fr(j,0,cnt[i]-1) diff[1].pb(i);
    }
    // show1d(n+1,cnt);

    fr(i,1,201)
    {
      sort(diff[i].begin(),diff[i].end(),greater<int>());
      // if(!diff[i].empty()) cnl("I: "<<i);
      while(!diff[i].empty())
      {
        int k = diff[i].back();
        // cnl(k);
        diff[i].ppb();
        if(k>i && !visited[k-i]) {visited[k-i]=1; ans+=i;cnl("case "<<k<<" "<<k-i);}
        else if(!visited[k+i]) {visited[k+i]=1; ans+=i; cnl("case "<<k<<" "<<k+i);}
        else diff[i+1].pb(k);
      }
    }
    // fr(i,0,201) indx[i]=i;
    // pairsort(cnt, indx,201);
    // fr(i,0,n+1)
    // {
    //   int i2 = indx[i];
    //   int x = cnt[i];
    //   fr(j,0,201)
    //   {
    //     if(!x) break;
    //     if(i2>j && !visited[i2-j])
    //     {
    //       visited[i2-j]=1;
    //       ans+=j; x--;
    //       cnl("CASE: "<<i2<<" "<<i2-j<<" "<<ans);
    //       if(!x) break;
    //     }
    //     if(!visited[i2+j])
    //     {
    //       visited[i2+j]=1;
    //       ans+=j; x--;
    //       cnl("CASE: "<<i2<<" "<<i2+j<<" "<<ans);
    //       if(!x) break;
    //     }
    //   }
    // }
    cnl(ans);
  }
}
