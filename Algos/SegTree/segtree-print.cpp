void printTree()
{
  cnl("TREEEEEEEEE: ");
  frr(k,1,h)
  {
// CHANGE THIS IF ITEM.V CANNOT BE PRINTED
    fr(i,1<<(k-1), 1<<k) csp(tree[i].val);
    cout << endl;
  }
  cout << endl;
}
