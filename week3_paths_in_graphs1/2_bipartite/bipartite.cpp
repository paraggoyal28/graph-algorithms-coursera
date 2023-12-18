#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

bool isBipartiteUtil(vector<vector<int>> &adj, int vertex, vector<int> &colors, int color)
{
  colors[vertex] = color;

  for (int neigh : adj[vertex])
  {
    if (colors[neigh] == -1)
    {
      if (!isBipartiteUtil(adj, neigh, colors, 1 - color))
      {
        return false;
      }
    }
    else if (colors[neigh] != 1 - color)
    {
      return false;
    }
  }

  return true;
}

int bipartite(vector<vector<int>> &adj)
{
  vector<int> colors(adj.size(), -1);

  for (size_t vertex = 0; vertex < adj.size(); ++vertex)
  {
    if (colors[vertex] == -1)
    {
      if (!isBipartiteUtil(adj, vertex, colors, 0))
      {
        return 0;
      }
    }
  }
  return 1;
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
  std::cout << bipartite(adj);
}
