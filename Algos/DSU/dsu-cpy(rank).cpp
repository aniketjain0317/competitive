class DisjSet
{
	int *rank, *parent, n;

public:
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}

	void merge(int x, int y)
	{
		int xset = find(x);
		int yset = find(y);
		if (xset == yset)
			return;
		if (rank[xset] < rank[yset])    	parent[xset] = yset;
		else if (rank[xset] > rank[yset])	parent[yset] = xset;
		else
    {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};
