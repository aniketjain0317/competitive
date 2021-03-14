class WeightedGraph
{
public:
  int n;
  vvi adj[N];
  bool visited[N]={};
  vi parent;

  WeightedGraph(int fn, vvi edges)
  {
    n=fn;
    for(auto v: edges) addEdge(v);
  }

  void addEdge(vi v)
  {
    adj[v[1]].pb({v[0],v[2]});
    adj[v[2]].pb({v[0],v[1]});
  }

  void clearVisited()
  {
    fr(i,0,N) visited[i]=0;
  }

  vi djikstra(int s)
  {
    vi dist(n,INF);
    dist[s]=0;
    priority_queue<vi,vvi, greater<vi>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
      auto tp = pq.top();
      int node = tp[1];
      pq.pop();
      for(auto edge: adj[node[1]])
      {
        auto child = edge[1];
        int new_val = dist[node]+edge[0];
        if(new_val<dist[child])
        {
          dist[child]=new_val;
          pq.push({dist[child], child});
        }
      }
    }
    return dist;
  }

  void bfs(int first)
  {
    queue<int> q;
    visited[first]=1;
    q.push(first);
    while(!q.empty())
    {
      auto node = q.front();
      for(auto edge: adj[node])
      {
        auto child=edge[1];
        if(!visited[child])
        {
          q.push(child);
          visited[child]=1;
        }
      }
      q.pop();
    }
    clearVisited();
  }

  void dfs(int node)
  {
    visited[node]=1;
    for(auto edge: adj[node])
    {
      auto child = edge[1];
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
