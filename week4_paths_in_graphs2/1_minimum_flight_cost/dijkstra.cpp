#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  vector<long long> dist(adj.size(), INF);

  dist[s] = 0;

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> smallestDist;
  smallestDist.push({0LL, s});

  while (!smallestDist.empty())
  {
    pair<long long, int> nearestVertex = smallestDist.top();
    smallestDist.pop();

    int vertex = nearestVertex.second;

    long long distance = nearestVertex.first;

    for (int neighIdx = 0; neighIdx < adj[vertex].size(); ++neighIdx)
    {
      int neigh = adj[vertex][neighIdx];
      if (dist[neigh] > dist[vertex] + cost[vertex][neighIdx])
      {
        dist[neigh] = dist[vertex] + cost[vertex][neighIdx];
        smallestDist.push({dist[neigh], neigh});
      }
    }
  }

  return dist[t] == INF ? -1 : dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
