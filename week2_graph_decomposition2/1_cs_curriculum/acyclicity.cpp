#include <iostream>
#include <vector>

using std::pair;
using std::vector;

bool hasCycle(vector<vector<int>> &adj, size_t vertex, vector<bool> &visited, vector<bool> &recStack)
{
  visited[vertex] = true;

  recStack[vertex] = true;

  for (int neigh : adj[vertex])
  {
    if (!visited[neigh] && hasCycle(adj, neigh, visited, recStack))
    {
      return true;
    }
    else if (recStack[neigh])
    {
      return true;
    }
  }

  recStack[vertex] = false;
  return false;
}

int acyclic(vector<vector<int>> &adj, size_t n)
{
  // write your code here
  vector<bool> visited(n, false), recStack(n, false);
  for (size_t vertex = 0; vertex < n; ++vertex)
  {
    if (!visited[vertex])
    {
      if (hasCycle(adj, vertex, visited, recStack))
      {
        return 1;
      }
    }
  }
  return 0;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj, n);
}
