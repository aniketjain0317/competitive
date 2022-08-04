#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int k=1;k<=t;k++)
        {
            long long n,c;
            cin >> n >> c ;
            vector<vector<long long>> a(n,vector<long long> (2));
            for(int i=0;i<n;i++)
                {
                    cin >> a[i][0] >> a[i][1];
                }
            long long ans=n;
            vector<long long> m(100001,0);
            for(int i=0;i<n;i++)
                {
                    for(int j=a[i][0]+1;j<a[i][1];j++)
                        m[j]++;

                }
            sort(m.begin(),m.end(),greater<int> ());
            for(int i=0;i<c;i++)
                {
                    ans+=m[i];

                }
                cout << "Case #" << k << ":" << " " << ans << endl;

        }

    return 0;
}
