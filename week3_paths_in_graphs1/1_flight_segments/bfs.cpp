#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using std::queue;
using std::vector;

int distance(vector<vector<int>> &adj, int s, int t)
{
  // write your code here
  size_t n = adj.size();
  vector<int> dist(n, INF);
  dist[s] = 0;
  queue<int> bfs;
  bfs.push(s);
  while (!bfs.empty())
  {
    int node = bfs.front();
    bfs.pop();

    if (node == t)
    {
      return dist[node];
    }

    for (int neigh : adj[node])
    {
      if (dist[neigh] == INF)
      {
        dist[neigh] = dist[node] + 1;
        bfs.push(neigh);
      }
    }
  }
  return -1;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
