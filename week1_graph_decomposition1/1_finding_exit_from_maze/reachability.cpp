#include <iostream>
#include <vector>

using std::pair;
using std::vector;

int reach(vector<vector<int>> &adj, int x, int y, vector<bool> &visited)
{
  // write your code here
  visited[x] = true;

  if (x == y)
    return 1;

  for (int neigh : adj[x])
  {
    if (!visited[neigh])
    {
      if (reach(adj, neigh, y, visited) == 1)
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
  vector<bool> visited(n, false);
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1, visited);
}
