struct item
{
  int val;
  friend ostream& operator<<(ostream& os, const item& x) {os << x.val; return os;}
};

class SegTree
{
public:
  int n, m, h;
  vector<item> tree;
  vector<vector<int>> len; // [left,right)
  vector<bool> marked;

  // CHANGE ITEM, NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;

  // OP is left to right.
  // i.e. v comes later and is merged into tree[x];
  void merge(int x, item& v)
  {
    marked[x] = 1;

    item ans;
    ans.val = max(tree[x].val, v.val);
    tree[x] = ans;
  }

  item single(int v)
  {return {v};}

  SegTree(int sz, vector<int> arr)
  {
    n = 1, h = 1;
    while(n<sz) h++, n<<=1; m=n<<1;

    tree.resize(m, single(NEUTRAL));
    marked.resize(m,0);
    for(int i = 0; i<sz; i++) tree[n+i] = single(arr[i]);
    // for(int i = n-1; i; i--)  tree[i]   = merge(tree[2*i], tree[2*i+1]);

    len.resize(m, {0,n});
    for(int i = n; i<m; i++)   len[i][0] = i-n,         len[i][1] = i-n+1;
    for(int i = n-1; i>0; i--) len[i][0] = len[2*i][0], len[i][1] = len[2*i+1][1];
  }

  void push(int x)
  {
    if (marked[x] && x<n) {
        merge(2*x, tree[x]);
        merge(2*x+1, tree[x]);
        marked[x] = false;
    }
  }

  item query(int l, int r, int x = 1)
  {
    int lx = len[x][0], rx = len[x][1];
    if(r<=lx || rx<=l) return single(NEUTRAL);
    if(l<=lx && rx<=r) return tree[x];
    push(x);
    item left  = query(i, 2*x);
    item right = query(i, 2*x+1);
    return merge(left, right);
  }

  void update(int l, int r, item v, int x = 1)
  {
    int lx = len[x][0], rx = len[x][1];
    if(r<=lx || rx<=l) return;
    merge(x, v);
    if(l<=lx && rx<=r) {merge(x, v); return;}
    push(x);
    update(l, r, v, 2*x);
    update(l, r, v, 2*x+1);
  }
};

// let range query = maximum
// we can update upper layers with changes too.
