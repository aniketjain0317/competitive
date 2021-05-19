// Upper Bound for k
// for lower bound, use k<=leftv

// GIVES Kth one in a binary string
int find(int k)
{
  // case for single element array
  // if(size==1) if(k!=tree[1].val) return -1;
  int x = 1;

  while(x<size)
  {
    int leftv = tree[2*x].val;
    if(k<leftv) x=2*x;
    else x=2*x+1, k=k-leftv;
  }
  return x-size;
}

// use if extra conditions regarding required index
// recursive implementation (can iterate over complete tree)
// GIVES FIRST ELEMENT ABOVE K
int find(int k, int x = 1)
{
  int lx = len[x].fs, rx = len[x].sn;

  if(tree[x].val<k) return -1;
  if(x>=size) return x-size;

  int ans = find(k,2*x);
  if(ans==-1) ans = find(k,2*x+1);
  return ans;
}
