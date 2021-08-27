class SegTree
{
public:
  int n, m;
  vector<int> tree;

  SegTree(int len, vector<int> &arr)
  {
    n = 1;
    while(n<len) n<<=1; m = n<<1;
    tree.resize(m,0);
    for(int i = 0; i<len; i++) tree[n+i]=arr[i];
    for(int i = n-1; i>=0; i--) tree[i] = tree[2*i]+tree[2*i+1];
  }

  void update(int i, int val)
  {
    tree[i+=n]=val;
    for(i>>=1; i; i>>=1) tree[i]=tree[2*i]+tree[2*i+1];
  }

  // [l,r)
  int query(int l, int r)
  {
    int ans = 0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ans+=tree[l++];
      if(r&1) ans+=tree[--r];
    }
    return ans;
  }
};
