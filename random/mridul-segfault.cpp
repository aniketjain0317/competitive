#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n+1]={};
    int ch[n+1]={};
    for(int i=0; i<n+1; i++) ch[i]=1;
    int mp[n+1]={};
    vector<int> adj[n+1];
    for(int i=1;i<=n;i++)
    {
      int a,b; cin >> a >> b;
      ar[i]=1;
      if(a!=-1)
      {
        adj[a].push_back(i);
        if(b==0) ch[a]=0;
        if(b==0) ch[i]=0;
      }
    }
    //if ci=1 and none of its children respect it push it in a vector
    for(int i=1; i<=n; i++)
    {
      if(ch[i])
      {
        
      }
    }
    if(ans==0)
        cout<<"-1";
    cout<<endl;
    return 0;
}
//
