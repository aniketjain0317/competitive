class DisjSet
{
	int *size, *parent, n;

public:
	DisjSet(int n)
	{
		size = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	void makeSet()
	{
		for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      size[i]=1;
    }
	}

	int find(int x)
	{
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}

	int merge(int x, int y)
	{
		int xset = find(x);
		int yset = find(y);

		if (xset == yset)
			return 0;
		if (size[xset] < size[yset]) swap(xset,yset);
		parent[yset] = xset;
		size[xset] += size[yset];
		return 1;
	}

  int getSize(int x)
  {
    int xset = find(x);
    return size[xset];
  }
};
