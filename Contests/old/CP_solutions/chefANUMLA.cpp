#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int size=1<<n;
    vector <int> sumset;
    for(int i=0;i<size;i++)
    {
      int temp;
      cin >> temp;
      sumset.push_back(temp);
    }

    vector <int> sumset2;
    int ans[n];
    ans[0]=sumset[1];
    sumset2.push_back(sumset[1]);


    for(int i=1;i<n;i++)
    {
      ans[i]=sumset[i+1];
      int size2=(1<<i)-1;
      for(int j=0;j<size2;j++)
      {
        int x=sumset2[j]+sumset[i+1];
        auto y=lower_bound(sumset.begin(),sumset.end(),x);
        sumset.erase(y);
       }
       for(int j=0;j<size2;j++)
       {
         int x=sumset2[j]+sumset[i+1];
         sumset2.push_back(x);
       }
       sumset2.push_back(sumset[i+1]);
    }
    for(auto x:ans) cout << x << " ";
    cout << endl;
  }
}
