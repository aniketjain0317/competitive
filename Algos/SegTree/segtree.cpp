// Range Queries, Point Update
// updates/queries: 0 indexed, storage array: 1 indexed

struct item
{
  int val;
};

struct SegTree
{
  int n;
  int h;
  int size;
  vector<item> tree;
  vector<pi> len;

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = INT_MAX;
  item merge(item& a, item& b)
  {
    item ans;
    ans.val = min(a.val, b.val);
    return ans;
  }

  item single(int v)
  {
    return {v};
  }

  void init(int sz, int arr[])
  {
    n = sz;
    h = ceil(log2(n))+1;
    size = 1LL<<(h-1);

    tree.resize(2*size, single(NEUTRAL));
    fr(i,0,n) tree[n+i] = single(arr[i]);
    frrb(i,n-1,0) tree[i] = merge(tree[2*x], tree[2*x+1]);

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
