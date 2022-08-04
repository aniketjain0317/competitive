#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
class SegTree
{
public:
  int n, m;
  vector<pair<int,int>> tree;

  SegTree(int len)
  {
    n = 1;
    while(n<len) n<<=1; m = n<<1;
    tree.resize(m, {INF, INF});
    for(int i = 0; i<len; i++) tree[n+i]={INF, i};
    for(int i = n-1; i>=0; i--) tree[i] = min(tree[2*i], tree[2*i+1]);
  }

  void update(int i, int val)
  {
    tree[i+=n]={val, i};
    for(i>>=1; i; i>>=1) tree[i]=min(tree[2*i], tree[2*i+1]);
  }

  // [l,r)
  pair<int,int> query(int l, int r)
  {
    pair<int,int> ans = {INF, INF};
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ans= min(ans, tree[l++]);
      if(r&1) ans= min(ans, tree[--r]);
    }
    return ans;
  }
};

vector<int> solve(int n, int k, vector<vector<int>> events) {
  vector<int> ans;
  SegTree st(n);
  for(auto &v: events)
  {
    if(v[0]==1) st.update(v[1], v[2]);
    else
    {
      int cnt = 0;
      while(true)
      {
        auto p = st.query(v[1], v[2]);
        if(p.first>v[3]) break;
        st.update(p.second, INF);
        cnt++;
      }
      ans.push_back(cnt);
    }
  }
  return ans;
}

int main()
{
  cout << solve(5, 9, {{1,0,3}, {1,2,5}, {2,0,4,3}, {1,1,4}, {1,2,7}, {2,1,3,6}, {1,3,6}, {1,4,5}, {2,0,5,6}});
}
