Q1:
my algo was just to find the kth largest from (shortest edge of every node)
it doesnt work tho. havent thought abt any other method yet.
Q2:
so originally i completely ignored k, which was the wrong approach.
However, I think djikstra still works here.
My djikstra code: https://github.com/aniketjain0317/competitive/tree/master/Topics/Graphs/Graph%20theory%20playlist/DjikstraAlgo.cpp

Changes I made:
  -instead of just distance and node, the pq also contains info about vagueness(i.e. unweighted distance)

  -global array of vagueness which contains info only about the optimal path

  -changes to how distance propogates(dist[s] initialised to 1 instead of 0, pq gives greatest value instead of shortest, new distance uses multiplication, not addition)

  -we only update the dist array if(vg<k), i.e. if the vagueness of the path taken is less than k

  -even if the node we selected from the pq is not in the optimal path, if its vg is less than the vagueness of the optimal path(which is stored in the global array vagueness), we push it to the pq without updating the dist array; hence, we open the door to updations of this suboptimal path's children which may be too far away for the optimal path to reach.

testing data used:
5 5 2
1 2 0.1
1 4 0.9
2 4 0.9
2 3 0.1
3 5 0.6
1

result:
1 0.81 0.01 0.9 0

Here, we see that node 3 can be reached with 0.081 strongness too, but since it is greater than 2 nodes apart, its not the answer.
Similarly, node 5 cannot be reached in 2 steps, hence the answer is 0 strongness

Q3:
We only need to find the cycle; removing ANY edge of the cycle will still result in a tree.
We can do this via dfs or bfs easily; I used dfs:
i used a global var parent, which just stores the parent of the current node in dfs.
this is used to avoid counting bidirectional edges as a cycle. Now if the child of a node is already visited AND its not its immediate parent, we have found the cycle.
