#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int t; cin >> t;
  while(t)
  {
    int n; double k; cin >> n >> k;
    double p[n];
    for(int i=0;i<n; i++) cin >> p[i];

    double sum=p[0];
    double maxx=0;

    for(int i=1;i<n;i++)
    {
      double delta = p[i]*(100.0/k) - sum;
      if(delta>0)
      {
        maxx=max(maxx,delta);
        // maxx=maxx+delta;
        // sum=sum+delta;
      }
      sum=sum+p[i];
    }
    long long ans=ceil(maxx);
    cout << ans << endl;
    t-=1;
  }
}
