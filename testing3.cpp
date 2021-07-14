#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> ourmap;
unordered_map<int, int> a;
vector<int> curr;
long long mod = 1000000007;

void powerSet(vector<int> v, int n, int index, long long &ans) {
    if(index == n) return;

    if(curr.size() != 0) {
        unordered_map<int, int> temp;
        int flag = 1;
        int currSize = curr.size();
        for(int i=0; i<currSize; i++) {
            for(int j=0; j<ourmap[curr[i]].size(); j++) {
                int x = ourmap[curr[i]][j];
                temp[x]++;
                if(temp[x] > 1) flag = 0;
            }
        }
        temp.clear();

        if(flag) {
            long long x = 1;
            for(int i=0; i<currSize; i++) {
                long long cnt = (long long)a[curr[i]];
                x = (x*a[curr[i]])%mod;
            }

            ans = (ans + x)%mod;
        }
    }

    for(int i=index+1; i<n; i++) {
        curr.push_back(v[i]);

        powerSet(v, n, i, ans);

        curr.pop_back();
    }
}

int main() {
    ourmap[2] = {2};
    ourmap[3] = {3};
    ourmap[5] = {5};
    ourmap[6] = {2,3};
    ourmap[7] = {7};
    ourmap[10] = {2,5};
    ourmap[11] = {11};
    ourmap[13] = {13};
    ourmap[14] = {2,7};
    ourmap[15] = {3,5};
    ourmap[17] = {17};
    ourmap[19] = {19};
    ourmap[21] = {3,7};
    ourmap[22] = {2,11};
    ourmap[23] = {23};
    ourmap[26] = {2,13};
    ourmap[29] = {29};
    ourmap[30] = {2,3,5};
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> v;
        a.clear();
        for(int i=0; i<n; i++) {
            int x;
            cin>>x;
            if(ourmap.count(x) > 0) {
                if(a.count(x) > 0) {
                    a[x]++;
                }
                else {
                    v.push_back(x);
                    a[x] = 1;
                }
            }
        }

        long long ans = 0;
        powerSet(v, v.size(), -1, ans);

        cout<<ans<<"\n";
    }
}
