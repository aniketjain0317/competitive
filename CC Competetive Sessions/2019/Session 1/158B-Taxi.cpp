#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int cnt[5]={};
    // 5 because arr[i] ranges from (1,4) so we need cnt[4] to exist
    // Alternatively, use int cnt[4]={}; with arr[i]-1 instead of just arr[i]

    for(int i=0;i<n;i++)
    {
      cnt[arr[i]]++;
    }

    int ans=0;

    // Algo: Add 4s, combine 3s and 1s first, add the remaining 3s,
    // then combine 2s with themselves, then combine 2s with 2 1s,
    // then combine 4 1s with themselves.

    ans+= cnt[4];
    if(cnt[3]>cnt[1])
    {
      ans+=cnt[1];
      cnt[3]-=cnt[1];
      cnt[1]=0;
    }
    else
    {
      ans+=cnt[3];
      cnt[1]-=cnt[3];
      cnt[3]=0;
    }
    if(cnt[3]) ans+=cnt[3];
    ans+= cnt[2]/2;
    if(cnt[2]%2)
    {
      ans+=1;
      cnt[1]-=2;
    }
    if(cnt[1]>0)
    {
      ans+=cnt[1]/4;
      if(cnt[1]%4) ans++;
      // Alternatively, use ans+=ceil(cnt[1]/4.0);
    }

    cout << ans << endl;
}
