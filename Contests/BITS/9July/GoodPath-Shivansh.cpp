#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> adj;
vector <int> m;
map<int, int> val; // {val, freq}
set<pair<int, int>> freq; // {freq, val}
int ans;

void dfs(int node, int prev, int depth) {

    int curr_freq = val[m[node]];
    auto it = freq.lower_bound({curr_freq, m[node]});
    auto p = *it;
    freq.erase(it);
    p.first++;
    val[m[node]]++;
    freq.insert(p);

    if((*(--freq.end())).first * 2 >= depth) {
        ans++;
    }

    // cout << node << '\n';
    // for(auto i : freq) {
    //     cout << i.first << " " << i.second << '\n';
    // }
    // cout << '\n';

    for(auto next : adj[node]) {
        if(next != prev) {
            dfs(next, node, depth + 1);
        }
    }

    curr_freq = val[m[node]];
    it = freq.lower_bound({curr_freq, m[node]});
    p = *it;
    freq.erase(it);
    p.first--;
    val[m[node]]--;
    freq.insert(p);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        adj.resize(n);
        m.resize(n);
        val.clear();
        freq.clear();
        for(int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for(int i = 0; i < n; i++) {
            cin >> m[i];
        }
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 0; i < n; i++) {
            freq.insert({0, m[i]});
        }
        ans = 0;
        dfs(0, 0, 1);
        cout << ans << '\n';
    }

    return 0;
}
