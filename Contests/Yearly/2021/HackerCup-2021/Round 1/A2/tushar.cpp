#include <bits/stdc++.h>
using namespace std;

long long dp[800000];
int main()
{   freopen("myans.txt","w",stdout);
    freopen("input.txt","r",stdin);

   int t;
   cin >> t;
   for(int tt=1;tt<=t;tt++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long mod=1e9+7;
        long long ans=0;
        char curr=s[0];
        int ind=1;
         dp[0]=0;
        for(int i=1;i<s.size();i++)
        {   dp[i]=0;

            if(s[i]=='X')
            {
                dp[i]=dp[i-1];
                if(curr=='O')
                    dp[i]=(dp[i]+ind)%mod;
                curr='X';
                ind=i+1;
            }
            else if(s[i]=='O')
            {
                dp[i]=dp[i-1];
                if(curr=='X')
                    dp[i]=(dp[i]+ind)%mod;
                curr='O';
                ind=i+1;
            }
            else
            {
                dp[i]=dp[i-1];
            }

        }
        for(int i=0;i<n;i++)
            {
                ans=(ans+dp[i])%mod;
            }
        cout << "Case #" << tt << ": " << ans <<endl;

    }
}
