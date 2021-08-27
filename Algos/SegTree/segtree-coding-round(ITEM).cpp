struct item
{
  int val;
};

class SegTree
{
public:
  int n,m;
  vector<item> tree;
  const int NEUTRAL = 0;
  item single(int x)
  {return {x};}
  item merge(item a, item b)
  {return {a.val+b.val};}

  SegTree(int len, vector<int> &arr)
  {
    n = 1;
    while(n<len) n<<=1; m=n<<1;
    tree.resize(m,single(NEUTRAL));
    for(int i = 0; i<len; i++) tree[n+i]=single(arr[i]);
    for(int i = n-1; i>=0; i--) tree[i]=merge(tree[2*i], tree[2*i+1]);
  }

  void update(int i, int val)
  {
    tree[i+=n]=single(val);
    for(i>>=1; i; i>>=1) tree[i]=merge(tree[2*i], tree[2*i+1]);
  }

  item query(int l, int r)
  {
    item ans = single(NEUTRAL);
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
      if(l&1) ans = merge(ans,tree[l++]);
      if(r&1) ans = merge(ans,tree[--r]);
    }
    return ans;
  }
};
