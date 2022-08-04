void printTree()
{
  cout << "TREEEEEEEEE: ";
  for(int i = 1; i<m; i++)
  {
    if(__builtin_popcountll(i)==1) cout << endl;
    cout << i << " ";
  }
  cout << endl;
}
