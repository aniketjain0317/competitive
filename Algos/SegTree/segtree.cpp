// Range Queries, Point Update
// updates/queries: 0 indexed, storage array: 1 indexed

struct item
{
  int val;
};

class SegTree
{
public:
  int n, m, h;
  vector<item> tree;
  vector<vector<int>> len; // [left,right)

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  item merge(item& a, item& b)
  {
    item ans;
    ans.val = (a.val+b.val);
    return ans;
  }
  item single(int v)
  {return {v};}

  SegTree(int sz, vector<int> arr)
  {
    n = 1, h = 1;
    while(n<sz) h++, n<<=1; m=n<<1;

    tree.resize(m, single(NEUTRAL));
    for(int i = 0; i<sz; i++) tree[n+i] = single(arr[i]);
    for(int i = n-1; i; i--)  tree[i]   = merge(tree[2*i], tree[2*i+1]);

    len.resize(m, {0,n});
    for(int i = n; i<m; i++) len[i][0] = i-n,         len[i][1] = i-n+1;
    for(int i = 1; i<n; i++) len[i][0] = len[2*i][0], len[i][1] = len[2*i+1][1];
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i, int v)
  {
    tree[i+=n] = single(v);
    while(i>>=1) tree[i] = merge(tree[2*i], tree[2*i+1]);
  }

  // [l,r), [lx, rx), 0-indexed
  item rec_query(int l, int r, int x=1)
  {
    int lx = len[x][0], rx = len[x][1];
    if(l<=lx && rx<=r) return tree[x];
    if(l>=rx || lx>=r) return single(NEUTRAL);

    item left = rec_query(l, r, 2*x);
    item right = rec_query(l, r, 2*x+1);
    return merge(left, right);
  }

  // [l,r)
  item query(int l, int r)
  {
    item ansLeft = single(NEUTRAL), ansRight = single(NEUTRAL);
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ansLeft = merge(ansLeft, tree[l++]);
      if(r&1) ansRight = merge(tree[--r], ansRight);
    }
    return merge(ansLeft, ansRight);
  }

  void printTree();
  int find(int k);
};
// length = 1<<(h-floor(log2(x)))
// left = (x - 1<<floor(log2(x))) * length
// right = left + length
