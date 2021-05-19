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

  // CHANGE NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  item merge(item& a, item& b)
  {
    item ans;
    ans.lx = a.lx;
    ans.ans = a.ans + b.ans;
    ans.clg = a.clg;

    if(b.clg < a.lx)
    {
      ans.ans--;
      if(a.ans = 1 && b.ans = 1) ans.clg = max(a.clg, b.clg);
    }
    return ans;
  }

  item single(int v)
  {
    return {1, v, clg[v]};
  }

  void init(int sz, int arr[])
  {
    n = sz;
    h = ceil(log2(n))+1;
    size = 1LL<<(h-1);
    tree.resize(2*size, single(NEUTRAL));
    len.resize(2*size, {0,size});
    fr(i,0,n) update(i, arr[i]);
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

  void printTree();
  int find(int k);
};
