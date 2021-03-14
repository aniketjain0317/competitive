#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a-1].pb(b-1);


vi adj[N];
int visited[N]={};
vi indeg;
vi ans;

void allTopSorts(int n);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int n,m; cin >> n >> m;
  indeg.resize(n,0);
  fr(i,0,m) {int a,b; cin >> a >> b; ud(a,b,adj);indeg[b-1]++;}
  allTopSorts(n);
}

void allTopSorts(int n)
{
  fr(v,0,n)
  {
    if(!indeg[v] && !visited[v])
    {
      for(auto child: adj[v]) indeg[child]--;
      ans.pb(v);
      visited[v]=1;

      allTopSorts(n);

      for(auto child: adj[v]) indeg[child]++;
      ans.pop_back();
      visited[v]=0;
    }
  }
  if(ans.size()==n)
  {
    vshow1d(ans);
  }
}
