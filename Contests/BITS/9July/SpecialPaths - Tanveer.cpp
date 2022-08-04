#include <bits/stdc++.h>
using namespace std;

#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define endl '\n'
#define int long long

const int N=1000000007;
const int INF=1000000000000000000;

int NMAX=100005;               ////////////////////check this value according to constraints
vector<int> parent,sz,vis;
vector<vector<int>> edge;


int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(int sp) {
    vis[sp]=1;
    for (int i=0;i<edge[sp].size();i++) {
        int child=edge[sp][i];
        if (vis[child]==0) {
            vis[child]=1;
            union_sets(sp,child);
            dfs(child);
        }
        else if (vis[child]==1) {
            union_sets(sp,child);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    test(t) {
        int n;
        cin >> n;

        edge.clear();
        edge.resize(n);
        parent.clear();
        parent.resize(n,0);
        vis.clear();
        vis.resize(n,-1); //////////////////DHYAN SE LIKHO
        sz.clear();
        sz.resize(n,0);

        for (int i=0;i<n;i++) {
            make_set(i);
        }

        for (int i=0;i<(n-1);i++) {
            int u,v;
            cin >> u >> v;
            edge[u-1].push_back(v-1);
            edge[v-1].push_back(u-1);
        }
        vector<pair<int,int>> vp;
        for (int i=0;i<n;i++) {
            int v;
            cin >> v;
            vp.push_back({v,i});
        }
        sort(vp.begin(),vp.end());
        int ans=0;
        for (int i=0;i<n;i++) {
            vector<int> values;
            int val=vp[i].first;
            int l=i;
            while (l<n && vp[l].first==val) {
                values.push_back(vp[l].second);
                vis[vp[l].second]=0;
                l++;
            }
            i=l-1;
            map<int,int> mp;
            for (int j=0;j<values.size();j++) {
                if (vis[values[j]]==0) {
                    dfs(values[j]);
                }
                // mp[find_set(values[j])]++;
            }
            for (int j=0;j<values.size();j++) {
                mp[find_set(values[j])]++;
            }
            for (auto it:mp) {
                int kk=it.second;
                ans+=(kk*(kk-1)/2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
