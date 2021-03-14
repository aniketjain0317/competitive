#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll visited[2100]={};// stored the depth of all the nodes
ll ar[2100]={};
void dfs(ll k)
{
    // k is a root
    // search kin kin ka parent k hai
    vector<ll>v;
    ll flag=0;
    for(ll i=0;i<2100;i++)
    {
        if(ar[i]==k)//k is a parent of i
        {
            visited[i]=visited[k]+1;// i ka level daal dia
            flag=1;
            v.push_back(i);
        }
    }
    if(flag==0)//k is not a parent at all
    {
        return;
    }
    else
    {
        for(ll i=0;i<v.size();i++)
        {
            dfs(i);
        }
    }

}
int main()
{
    ll n;
    cin>>n;
    vector<ll>root;


    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i]==(-1))
        {

            root.push_back(i);//i is a root
        }
    }
    for(ll i=0;i<root.size();i++)
    {
        dfs(root[i]);
    }
    sort(visited,visited+2100);
    if(visited[2099]>=2)
    {
        cout<<"3"<<endl;

    }
    else if(visited[2099]>=1)
    {
        cout<<"2"<<endl;

    }
    else
    {
        cout<<"1"<<endl;
    }
    return 0;
    //run dfs
}
