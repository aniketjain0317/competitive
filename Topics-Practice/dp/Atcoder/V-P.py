n,m = [int(x) for x in input().split()]
adj = [[] for i in range(n)]
for i in range(n-1):
  u,v = [int(x) for x in input().split()]
  adj[u-1].append(v-1)
  adj[v-1].append(u-1)

ans = [0 for i in range(n)]
subs = [1 for i in range(n)]

def getSubs(node, parent):
  for child in adj[node]:
    if child is not parent:
      getSubs(child,node)
  for child in adj[node]:
    if child is not parent:
      subs[node]*=subs[child]
  subs[node]+=1
def getAns(node, parent):
  ans[node] = subs[node]-1
  if node is not parent:
    ans[node]*=(1+ans[parent]/subs[node])
  for child in adj[node]:
    if child is not parent:
      getAns(child,node)

getSubs(0,0)
getAns(0,0)
for i in range(n):
  print(int(ans[i]%m))
