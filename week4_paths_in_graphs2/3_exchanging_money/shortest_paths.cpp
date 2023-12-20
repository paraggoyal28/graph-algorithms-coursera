#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#define INF std::numeric_limits<long long>::max()

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;
void shortest_paths(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest)
{
  int n = adj.size();
  distance[s] = 0;
  reachable[s] = 1;
  queue<int> negativeDistVertices;

  vector<int> prev(n);
  for (int itr = 0; itr < n; ++itr)
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
          reachable[neighbor] = 1;
          if (itr == n - 1)
          {
            negativeDistVertices.push(neighbor);
          }
        }
      }
    }
  }

  vector<int> visited(n, 0);
  while (!negativeDistVertices.empty())
  {
    int u = negativeDistVertices.front();
    negativeDistVertices.pop();
    visited[u] = 1;
    shortest[u] = 0;
    for (int i = 0; i < adj[u].size(); i++)
    {
      int v = adj[u][i];
      if (!visited[v])
      {
        negativeDistVertices.push(v);
        visited[v] = 1;
        shortest[v] = 0;
      }
    }
  }
  distance[s] = 0;
}

int main()
{
  int n, m, s;
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
  std::cin >> s;
  s--;
  vector<long long> distance(n, INF);
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++)
  {
    if (!reachable[i])
    {
      std::cout << "*\n";
    }
    else if (!shortest[i])
    {
      std::cout << "-\n";
    }
    else
    {
      std::cout << distance[i] << "\n";
    }
  }
}
