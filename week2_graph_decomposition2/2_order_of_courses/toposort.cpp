#include <iostream>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<int> &used, vector<int> &order, int x)
{
  // write your code here
  used[x] = true;

  for (int neigh : adj[x])
  {
    if (!used[neigh])
    {
      dfs(adj, used, order, neigh);
    }
  }

  order.push_back(x);
}

vector<int> toposort(vector<vector<int>> adj)
{
  vector<int> used(adj.size(), 0);
  vector<int> order;
  for (size_t vertex = 0; vertex < adj.size(); ++vertex)
  {
    if (!used[vertex])
    {
      dfs(adj, used, order, vertex);
    }
  }
  reverse(order.begin(), order.end());
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++)
  {
    std::cout << order[i] + 1 << " ";
  }
}
