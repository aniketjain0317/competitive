// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define nl cout << endl
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define test(t) int t; cin << t; while(t--)
#define cinp(n,arr) forr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 50000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

ll ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
int main()
{
  int ans=0;
  vector<int> cnt;
  cnt.assign(N,0);
  fr(i,1,N+1)
  {
    fr(j,(i/4)+1,i)
    {
      int x = i*(4*j-i);
      if(x>N) break;
      cnt[x]++;
    }
    if(cnt[i]==1)
    {
      ans++;
      // cout <<ans<< ". "<< i << "\n";
    }
  }
  ll ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  int time = ms2-ms1;
  cout << ans<<"   "<<time<< endl;
}
