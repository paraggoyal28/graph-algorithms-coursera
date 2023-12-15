#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int vertex)
{
  visited[vertex] = true;

  for (int neigh : adj[vertex])
  {
    if (!visited[neigh])
    {
      dfs(adj, visited, neigh);
    }
  }
}

int number_of_components(vector<vector<int>> &adj, int n)
{
  int res = 0;

  vector<bool> visited(n, false);

  for (int i = 0; i < n; ++i)
  {
    if (!visited[i])
    {
      dfs(adj, visited, i);
      res += 1;
    }
  }

  return res;
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
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj, n);
}
