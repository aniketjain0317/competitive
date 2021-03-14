#include <bits/stdc++.h>
using namespace std;
long long int dp[3000][3000];
char ans[3000][3000];
pair<int, int> nxt[3000][3000];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string a, b;
  cin >> a >> b;
  int na = a.size();
  int nb = b.size();
  if (a[0] == b[0]) {
    dp[0][0] = 1;
    ans[0][0] = a[0];
  }
  else {
    dp[0][0] = 0;
    ans[0][0] = 0;
  }
  nxt[0][0] = { -1, -1};
  for (int j = 1; j < nb; j++) {
    if (a[0] == b[j]) {
      dp[0][j] = 1;
      ans[0][j] = a[0];
      nxt[0][j] = { -1, -1};
    }
    else {
      dp[0][j] = dp[0][j - 1];
      nxt[0][j] = {0, j - 1};
    }
  }
  for (int i = 1; i < na; i++) {
    if (a[i] == b[0]) {
      dp[i][0] = 1;
      ans[i][0] = b[0];
      nxt[i][0] = { -1, -1};
    }
    else {
      dp[i][0] = dp[i - 1][0];
      nxt[i][0] = { i - 1, 0};
    }
  }
  for (int i = 1; i < na; i++) {
    for (int j = 1; j < nb; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        ans[i][j] = a[i];
        nxt[i][j] = {i - 1, j - 1};
      }
      else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          nxt[i][j] = {i - 1, j};
        }
        else {
          nxt[i][j] = {i, j - 1};
        }
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = na - 1, j = nb - 1, ilast, jlast;
  string res = "";
  while (i != -1) {
    if (ans[i][j]) {
      res += ans[i][j];
    }
    ilast = i, jlast = j;
    i = nxt[ilast][jlast].first;
    j = nxt[ilast][jlast].second;
  }
  reverse(res.begin(), res.end());
  cout << res;
  return 0;
}
