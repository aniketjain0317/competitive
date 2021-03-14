#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

template<typename T>
T hungarian(const vector<vector<T>>& cost) {
    const T INF = numeric_limits<T>::max();
    int n = cost.size(), m = cost[0].size();
    vector<T> u(n + 1), v(m + 1), dist(m + 1);
    vector<int> p(m + 1), way(m + 1), used(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        fill(dist.begin(), dist.end(), INF);
        do {
            used[j0] = i;
            int i0 = p[j0], j1 = -1;
            T delta = INF;
            for (int j = 1; j <= m; ++j) if (used[j] != i) {
                T cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < dist[j]) dist[j] = cur, way[j] = j0;
                if (dist[j] < delta) delta = dist[j], j1 = j;
            }
            forn(j, m + 1) {
                if (used[j] == i) u[p[j]] += delta, v[j] -= delta;
                else dist[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        for (int j1; j0; j0 = j1)
            p[j0] = p[j1 = way[j0]];
    }

    return -v[0];
}

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> t(n);
	forn(i, n){
		scanf("%d", &t[i]);
		--t[i];
	}
	vector<vector<int>> cost(n, vector<int>(2 * n));
	forn(i, n) forn(j, 2 * n) cost[i][j] = abs(t[i] - j);
	printf("%d\n", hungarian(cost));
}

int main() {
	int q;
	scanf("%d", &q);
	forn(_, q) solve();
}
