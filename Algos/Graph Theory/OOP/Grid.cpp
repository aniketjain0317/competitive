class Grid
{
public:
  int n,m;
  vpi dir;
  int sz;

  map<pi,bool> walls;
  bool used_walls=0;

  map<pi,bool> visited;
  map<pi,pi> parent;

  Grid(int fn, int fm, vpi fdir)
  {
    n=fn;
    m=fm;
    dir=fdir;
    sz=dir.size();
  }

  void addWalls(vpi fwalls)
  {
    used_walls=1;
    for(pi p: fwalls) walls[p]=1;
  }

  vpi neighbors(pi p)
  {
    vpi ans;
    for(pi d: dir)
    {
      pi nx(p.fs+d.fs,p.sn-d.sn);
      if(nx.fs<0 || nx.fs>=n) continue;
      if(nx.sn<0 || nx.sn>=m) continue;
      if(used_walls && walls[nx]==1) continue;
      ans.pb(nx);
    }
    return ans;
  }

  void bfs(pi first)
  {
    visited[first]=1;
    parent[first]=mp(-1,-1);
    queue<pi> q;
    q.push(first);
    while(!q.empty())
    {
      pi node = q.front();
      for(auto child: neighbors(node))
      {
        if(!visited[child])
        {
          q.push(child);
          visited[child]=1;
          parent[child]=node;
        }
      }
      q.pop();
    }
  }

  vpi findPath(pi start, pi end)
  {
    bfs(start);
    vpi result;
    pi node = end;
    if(parent.find(end)==parent.end()) return result;
    while(node!=mp(-1,-1))
    {
      result.pb(node);
      node=parent[node];
    }
    reverse(all(result));
    if(result[0]!=start) result.clear();
    return result;
  }
};
