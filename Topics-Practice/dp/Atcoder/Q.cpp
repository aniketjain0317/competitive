#include <bits/stdc++.h>
using namespace std;

#define int long long
// class SegTree
// {
// public:
//   int n;
//   vector<int> arr;
//   int SINGLE = 0;
//
//   SegTree(int m)
//   {
//     int h = log2(m)+2;
//     n = 1<<h;
//     arr.resize(2*n,SINGLE);
//   }
//
//   int merge(int a, int b)
//   {
//     return max(a,b);
//   }
//
//   // [l,r)
//   void update(int l, int r, int v)
//   {
//     for(int lx=n+l, rx=n+r; lx<rx; lx>>=1, rx>>=1)
//     {
//       if(lx&1) arr[lx] = merge(arr[lx++], v);
//       if(rx&1) arr[rx] = merge(arr[--rx], v);
//     }
//   }
//
//   int query(int q)
//   {
//     int ans = 0;
//     for(int x=n+q; x; x>>=1) ans = merge(ans, arr[x]);
//     return ans;
//   }
//
//   void printTree()
//   {
//     int nx = 1<<1;
//     for(int i = 1; i<(2*n); i++)
//     {
//       if(i==nx)
//       {
//         cout << endl;
//         nx<<=1;
//       }
//       cout << arr[i] << " ";
//     }
//     cout << endl;
//   }
// };


struct item
{
  int val;
};

struct SegTree
{
  using pi = pair<int,int>;
  #define fr(i,a,b) for(int i = a; i<b; i++)
  #define fs first
  #define sn second

  int n;
  int h;
  int size;
  vector<item> tree;
  vector<pi> len;

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  item merge(item& a, item& b)
  {
    item ans;
    ans.val = max(a.val, b.val);
    return ans;
  }

  item single(int v)
  {
    return {v};
  }

  void init(int sz)
  {
    n = sz;
    h = ceil(log2(n))+1;
    size = 1LL<<(h-1);

    tree.resize(2*size, single(NEUTRAL));
    // fr(i,0,n) tree[n+i] = single(arr[i]);
    // frrb(i,n-1,0) tree[i] = merge(tree[2*x], tree[2*x+1]);

    // length = 1<<(h-floor(log2(x)))
    // left = (x - 1<<floor(log2(x))) * length
    // right = left + length
    len.resize(2*size, {0,size});
    fr(x,1,size)
    {
      int l = len[x].fs, r = len[x].sn;
      int m = (l+r)/2;
      len[2*x]={l,m};
      len[2*x+1]={m,r};
    }
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i, int v)
  {
    int x = size + i;
    tree[x] = single(v);
    while(x>>=1)
      tree[x] = merge(tree[2*x], tree[2*x+1]);
  }

  // [l,r), [lx, rx), 0-indexed
  item query(int l, int r, int x=1)
  {
    int lx = len[x].fs, rx = len[x].sn;
    if(lx>=l && rx<=r) return tree[x];
    if(rx<=l || lx>=r) return single(NEUTRAL);
    item left = query(l, r, 2*x);
    item right = query(l, r, 2*x+1);
    return merge(left, right);
  }

  // [l,r)
  item iterative_query(int l, int r)
  {
    item ans = single(NEUTRAL);
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1)
    {
      if(l&1) ans = merge(ans, tree[l++]); // if l is odd: right one
      if(r&1) ans = merge(ans, tree[--r]); // if (r-1) is even: left one
    }
    return ans;
  }

  void printTree();
  int find(int k);
};

int32_t main()
{
  int n; cin >> n;
  int h[n+1]={}, a[n+1]={};
  for(int i =1; i<=n; i++) cin >> h[i];
  for(int i =1; i<=n; i++) cin >> a[i];
  SegTree st; st.init(n+2);
  int ans = 0;
  for(int i =1; i<=n; i++)
  {
    int val = a[i] + st.query(0,h[i]).val;
    st.update(h[i], val);
    ans = max(ans, val);
  }
  cout << ans << endl;
}
// 3  1 4 2
// 10 20 30 40
// query(i) = max(arr[j]) where j<i;
// update(i) = arr[i] = max(arr[])
