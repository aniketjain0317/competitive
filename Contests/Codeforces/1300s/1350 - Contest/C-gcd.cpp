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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int garr[100000]={};
int rgarr[100000]={};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements

int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
        garr[i]=result;
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

int findGCDr(int arr[], int n)
{
    int result = arr[n-1];
    for (int i = n-1; i >= 1; i--)
    {
        result = gcd(arr[i], result);
        rgarr[i]=result;
        if(result == 1)
        {
           return 1;
        }

    }
    return result;
}

ll findlcm(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ainp(n,arr);
  int arr2[n];
  int g = findGCD(arr,n);
  fr(i,0,n)
  {
    arr[i]=arr[i]/g;
    garr[i]=1;
    rgarr[i]=1;
  }
  garr[0]=arr[0];
  rgarr[n-1]=arr[n-1];
  findGCD(arr,n);
  findGCDr(arr,n);
  fr(i,1,n-1)
  {
    arr2[i] = gcd(garr[i-1],rgarr[i+1]);
  }
  arr2[0]=rgarr[1];
  arr2[n-1]=garr[n-2];  
  ll ans = g * findlcm(arr2,n);
  cnl(ans);
}
