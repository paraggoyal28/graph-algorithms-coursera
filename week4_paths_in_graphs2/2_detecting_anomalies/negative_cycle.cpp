#include <iostream>
#include <limits>
#include <vector>
#define INF std::numeric_limits<long long>::max()

using std::vector;

int bellman_ford(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &distance)
{
  int n = adj.size();
  distance[s] = 0;
  for (int itr = 0; itr < n - 1; ++itr)
  {
    for (int vertex = 0; vertex < n; ++vertex)
    {
      int neighbors = adj[vertex].size();
      for (int neighIdx = 0; neighIdx < neighbors; ++neighIdx)
      {
        int neighbor = adj[vertex][neighIdx];
        if (distance[vertex] != INF && distance[neighbor] > distance[vertex] + cost[vertex][neighIdx])
        {
          distance[neighbor] = distance[vertex] + cost[vertex][neighIdx];
        }
      }
    }
  }

  for (int vertex = 0; vertex < n; ++vertex)
  {
    int neighbors = adj[vertex].size();
    for (int neighIdx = 0; neighIdx < neighbors; ++neighIdx)
    {
      int neighbor = adj[vertex][neighIdx];
      if (distance[vertex] != INF && distance[neighbor] > distance[vertex] + cost[vertex][neighIdx])
      {
        return 1;
      }
    }
  }
  return 0;
}

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost)
{
  // write your code here
  int n = adj.size();
  vector<long long> distance(n, INF);
  for (int i = 0; i < n; ++i)
  {
    if (distance[i] == INF && bellman_ford(adj, cost, i, distance))
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());

  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
