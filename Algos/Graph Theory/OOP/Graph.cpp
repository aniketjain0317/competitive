class Graph
{
public:
  int n;
  vi adj[N];
  bool visited[N]={};
  vi dist;
  vi parent;
  int max_dist=-1;

  Graph(int fn, vvi edges)
  {
    n=fn;
    for(auto v: edges) addEdge(v);
  }

  void addEdge(vi v)
  {
    adj[v[0]].pb(v[1]);
    adj[v[1]].pb(v[0]);
  }

  void clearVisited()
  {
    fr(i,0,N) visited[i]=0;
  }

  void bfsCalcDist(int first)
  {
    dist.resize(n,0);
    parent.resize(n,-1);
    queue<int> q;
    visited[first]=1;
    q.push(first);
    while(!q.empty())
    {
      int node = q.front();
      for(auto child: adj[node])
      {
        if(!visited[child])
        {
          dist[child]=dist[node]+1;
          mxs(max_dist,dist[child]);
          parent[child]=node;
          visited[child]=1;
          q.push(child);
        }
      }
      q.pop();
    }
    clearVisited();
  }

  vi findPath(int start, int end)
  {
    bfsCalcDist(start);
    vi result;
    int node=end;
    if(parent[node]==-1) return result;
    while(node!=-1)
    {
      result.pb(node);
      node=parent[node];
    }
    reverse(all(result));
    if(result[0]!=start) result.clear();
    return result;
  }

  void bfs(int first)
  {
    queue<int> q;
    visited[first]=1;
    q.push(first);
    while(!q.empty())
    {
      auto node = q.front();
      for(auto child: adj[node])
      {
        if(!visited[child])
        {
          q.push(child);
          visited[child]=1;
        }
      }
      q.pop();
    }
  }

  void dfs(int node)
  {
    visited[node]=1;
    for(auto child: adj[node])
    {
      if(!visited[child])
      {
        dfs(child);
      }
    }
  }

  void dfsBase()
  {
    fr(i,0,n)
    {
      if(!visited[i]) dfs(i);
    }
    clearVisited();
  }
};
