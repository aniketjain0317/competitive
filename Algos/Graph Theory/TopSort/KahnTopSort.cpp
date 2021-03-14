#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a-1].pb(b-1);


vi adj[N];
int visited[N]={};
int indeg[N]={};

vi kahnTopSort(int n);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int n,m; cin >> n >> m;
  fr(i,0,m) {int a,b; cin >> a >> b; ud(a,b,adj);indeg[b-1]++;}

  vi ans = kahnTopSort(n);
  vshow1d(ans);
}

vi kahnTopSort(int n)
{
  vi set0, ans;
  fr(i,0,n) if(!indeg[i]) set0.pb(i);

  while(!set0.empty())
  {
    int n=set0.back();
    set0.pop_back();

    ans.pb(n);
    for(auto child: adj[n]) if(!--indeg[child]) set0.pb(child);
  }

  // for checking if graph is really acyclic or not
  // fr(i,0,n) if(indeg[i]) {ans.clear(); return ans;}
  return ans;
}
